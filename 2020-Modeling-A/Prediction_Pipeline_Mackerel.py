# In[1]:
#Herring Model is just of the same theory.
import pandas as pd
import numpy as np
from pygam import LinearGAM #the integral algorithm can be found in Github
import matplotlib.pyplot as plt

# In[2]:
# train a model:
mackerel_data=pd.read_csv("temp_mackerel.csv")
mackerel_data.head(10)

# In[3]:
X_train=mackerel_data.drop(['Value','Date'],axis=1).values
y_train=(mackerel_data['Value'].to_numpy())
print(type(X_train))
print(type(y_train))
X_train.shape

# In[4]:
lams=np.random.rand(100,3)
lams=lams*3
lams=np.exp(lams)
gam=LinearGAM(n_splines=25).gridsearch(X_train,y_train,lam=lams)

# In[7]:
num=20
for num in range(20,71):
    target_file="future_test/rcp85-year/"+"20"+str(num)+".csv"
    dff=pd.read_csv(target_file)
    dff.dropna(inplace=True)
    dff['Temp']-=273.15
    
    X_test=dff.drop(['Date'],axis=1).as_matrix()
    y_test=gam.predict(X_test)
    dff['predict_value']=y_test
    dff=dff.loc[dff['predict_value']>0]
    
    dff.to_csv("diff_future_predict_mackerel/rcp85-year/"+"20"+str(num)+".csv")

# In[5]:
gam.summary()

# In[ ]:
titles = ["Lon","Lat","Temp_Diff"]
plt.figure()
fig, axs = plt.subplots(1,3,figsize=(40, 5))

for i, ax in enumerate(axs):
    XX = gam.generate_X_grid(term=i)
    ax.plot(XX[:, i], gam.partial_dependence(term=i, X=XX))
    ax.plot(XX[:, i], gam.partial_dependence(term=i, X=XX, width=.95)[1], c='r', ls='--')
    if i == 0:
        ax.set_ylim(-30,30)
    ax.set_title(titles[i])