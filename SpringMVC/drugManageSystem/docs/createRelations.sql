create table EMPLOYEE
(
    EMPLOYEEID char(6),
    NAME       varchar(16) NOT NULL,
    PASSWORD   varchar(16) NOT NULL,
    PHONE      varchar(11) NOT NULL,
    POSITION   varchar(16) NOT NULL,
    LEADERID   char(6),
    primary key (EMPLOYEEID),
    foreign key (LEADERID) REFERENCES EMPLOYEE (EMPLOYEEID)
);
-- -------员工的职位名约束
alter table EMPLOYEE
    add constraint POSITIONCONSTRAINT check (POSITION in ('ADMIN', 'MEDMANAGER', 'SALER', 'BUYER', 'RETURNER'));

create table FACTORY
(
    FACTORYID   char(6),
    FACTORYNAME varchar(30) NOT NULL,
    ADDRESS     varchar(30) NOT NULL,
    PHONE       varchar(11) NOT NULL,
    primary key (FACTORYID)
);

create table BUYRECORD
(
    BUYRECORDID varchar(11),
    DATE        date    NOT NULL,
    TIME        time    NOT NULL,
    FACTORYID   char(6) NOT NULL,
    BUYERID     char(6) NOT NULL,
    primary key (BUYRECORDID),
    FOREIGN KEY (FACTORYID) REFERENCES FACTORY (FACTORYID),
    FOREIGN KEY (BUYERID) REFERENCES EMPLOYEE (EMPLOYEEID)

);
create table CLIENT
(
    CLIENTID char(6),
    NAME     varchar(16) NOT NULL,
    PHONE    varchar(11) NOT NULL,
    primary key (CLIENTID)
);
create table SALERECORD
(
    SALERECORDID varchar(11),
    DATE         date    NOT NULL,
    TIME         time    NOT NULL,
    CLIENTID     char(6) NOT NULL, --
    SALERID      char(6) NOT NULL, --
    primary key (SALERECORDID),
    FOREIGN KEY (CLIENTID) REFERENCES CLIENT (CLIENTID),
    FOREIGN KEY (SALERID) REFERENCES EMPLOYEE (EMPLOYEEID)
);
create table TYPE
(
    ID       char(6),
    NAME     varchar(10) NOT NULL,
    FATHERID char(6),
    primary key (ID),
    FOREIGN KEY (FATHERID) REFERENCES TYPE (ID)
);
create table MEDICINE
(
    MEDICINEID   char(6),
    MEDICINENAME varchar(30) NOT NULL,
    TYPEID       char(6)     NOT NULL,
    BUYPRICE     real        NOT NULL,
    SALEPRICE    real        NOT NULL,
    PRODUCERID   char(6)     NOT NULL,
    FOREIGN KEY (TYPEID) REFERENCES TYPE (ID),
    primary key (MEDICINEID),
    FOREIGN KEY (PRODUCERID) REFERENCES FACTORY (FACTORYID)
);
create table BUYRECORDEXP
(
    BUYRECORDID varchar(11),
    MEDICINEID  char(6),
    primary key (BUYRECORDID, MEDICINEID),
    QUANTITY    int  NOT NULL,
    BUYPRICE    real NOT NULL,
    PRODUCEDATE date not null,
    FOREIGN KEY (BUYRECORDID) REFERENCES BUYRECORD (BUYRECORDID),
    FOREIGN KEY (MEDICINEID) REFERENCES MEDICINE (MEDICINEID)
);
create table SALERECORDEXP
(
    SALERECORDID varchar(11),
    MEDICINEID   char(6),
    QUANTITY     int  NOT NULL,
    SALEPRICE    real NOT NULL,
    PRODUCEDATE  date not null,
    primary key (SALERECORDID, MEDICINEID, PRODUCEDATE),
    FOREIGN KEY (SALERECORDID) REFERENCES SALERECORD (SALERECORDID),
    FOREIGN KEY (MEDICINEID) REFERENCES MEDICINE (MEDICINEID)
);
create table STOCK
(
    MEDICINEID    char(6),
    PRODUCEDATE   date NOT NULL,
    primary key (MEDICINEID, PRODUCEDATE),
    EFFICIENTDATE date NOT NULL,
    STOCK         int  NOT NULL,
    FOREIGN KEY (MEDICINEID) REFERENCES MEDICINE (MEDICINEID)
);
create table RETURNFACTORY
(
    MEDICINEID    char(6),
    PRODUCEDATE   date NOT NULL,
    primary key (MEDICINEID, PRODUCEDATE),
    EFFICIENTDATE date NOT NULL,
    STOCK         int  NOT NULL,
    FOREIGN KEY (MEDICINEID) REFERENCES MEDICINE (MEDICINEID)
);

insert into EMPLOYEE
values('000001','老板','123456',
       '1234567890','ADMIN',null);
insert into EMPLOYEE
values('000002','王凌','123456','1234567890',
       'MEDMANAGER','000001');
insert into EMPLOYEE
values('000003','陈秋','123456','1234567890',
       'SALER','000001');
insert into EMPLOYEE
values('000004','李世明','123456','1234567890',
       'BUYER','000001');
insert into EMPLOYEE
values('000005','刘莎','123456','1234567890',
       'RETURNER','000001');

insert into BUYRECORD
	values('00000000010',
	NOW(),NOW(),
	'1','000004'
	);

insert into BUYRECORDEXP
	values('00000000010',
	'200001','12','7.1','2017-12-1'),
	('00000000010',
	'200000','25','3.5','2017-5-24'),
	('00000000010',
	'200002','45','1.6','2017-12-1');

insert into SALERECORD
	values('00000000010',
	NOW(),NOW(),
	'1','000003'
	);

insert into SALERECORDEXP
values('00000000010',
	'200001','2','8.1','2017-12-1'),
	('00000000010',
	'200000','5','4.5','2017-5-24');

insert into STOCK
	values('200001','2017-12-1',
	'2018-12-1','10'),
	('200000','2017-5-24',
	'2018-5-24','20'),
	('200002','2017-12-1',
	'2018-12-1','45');

