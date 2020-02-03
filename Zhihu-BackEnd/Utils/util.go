package Utils

import (
	"crypto/rand"
	"fmt"
	jwt "github.com/dgrijalva/jwt-go"
	_ "golang.org/x/crypto/scrypt"
	"io"
	"time"
)

var jwtSecret []byte

type Claims struct {
	Username string `json:"username"`
	Password string `json:"password"`
	jwt.StandardClaims
}

func GenerateToken(username, password string) (string, error) {
	nowTime := time.Now()
	expireTime := nowTime.Add(3 * time.Hour)
	salt := make([]byte, 8)
	_, err := io.ReadFull(rand.Reader, salt)
	PasswordHash, err := scrypt.Key([]byte(password), salt, 32768, 8, 1, 8)
	claims := Claims{
		username,
		string(PasswordHash),
		jwt.StandardClaims {
			ExpiresAt : expireTime.Unix(),
			Issuer : "duslia-blog",
		},
	}

	tokenClaims := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	token, err := tokenClaims.SignedString(jwtSecret)
	fmt.Println("token: ", token )
	return token, err
}

func ParseToken(token string) (*Claims, error) {
	tokenClaims, err := jwt.ParseWithClaims(token, &Claims{},
		func(token *jwt.Token) (interface{}, error) {
			return jwtSecret, nil
		})
	if tokenClaims != nil {
		if claims, ok := tokenClaims.Claims.(*Claims); ok && tokenClaims.Valid {
			return claims, nil
		}
	}
	return nil, err
}