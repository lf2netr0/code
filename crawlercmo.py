import requests
import re
import datetime
from bs4 import BeautifulSoup as bs

five_second=[]
start = datetime.time(8,45,00,0)
stop=datetime.time(13,45,00,0)
space=datetime.timedelta(seconds=5)
t1=datetime.datetime.now()


def get_price():
    rs=requests.session()
    headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.112 Safari/537.36'
    }
    res = rs.get('https://www.cmoney.tw/vt/ashx/foaccountdata.ashx?act=GetFuturesPrice&futKey=MXF&futMonth=201604&isSell=false&prFlag=LimitPr',headers=headers)
    m=re.findall(r'"BuyPr1":.*?,',res.text)
    m[0]=re.sub(r'"BuyPr1":',"",m[0])
    m[0]=re.sub(r',',"",m[0])
    m[0]=float(m[0])
    print(m[0])
    return m[0]

def w_onemk(t3):
    d=datetime.date.today()
    d=str(d)+'-1MK.txt'
    f=open(d,'a')
    f.write("{'open':'"+str(five_second[0])+"','close':'"+str(five_second[11])+"','max':'"+str(max(five_second))+"','min':'"+str(min(five_second))+"','time':"+str(t3)+"'}'\n")
    f.close()
    print('1MK-stored')
    
def w_mk(a,b,t3):
    d=datetime.date.today()
    d1=str(d)+'-'+str(a)+'MK.txt'
    d2=str(d)+'-'+str(b)+'MK.txt'
    f1=open(d1,'r')
    f2=open(d2,'a')
    x=f1.read()
    op=re.findall(r"'open':'.*?'",x)
    cl=re.findall(r"'close':'.*?'",x)
    ma=re.findall(r"'max':'.*?'",x)
    mi=re.findall(r"'min':'.*?'",x)
    for i in range(len(op)):
        op[i]=re.sub(r"'open':'","",op[i])
        op[i]=re.sub(r"'","",op[i])
        cl[i]=re.sub(r"'close':'","",cl[i])
        cl[i]=re.sub(r"'","",cl[i])
        ma[i]=re.sub(r"'max':'","",ma[i])
        ma[i]=re.sub(r"'","",ma[i])
        mi[i]=re.sub(r"'min':'","",mi[i])
        mi[i]=re.sub(r"'","",mi[i])
        op[i]=float(op[i])
        cl[i]=float(cl[i])
        ma[i]=float(ma[i])
        mi[i]=float(mi[i])
    Op=[]
    Cl=[]
    Ma=[]
    Mi=[]
    for i in range(b//a):
        Op.append(op.pop())
        Cl.append(cl.pop())
        Ma.append(ma.pop())
        Mi.append(mi.pop())
    f2.write("{'open':'"+str(Op[(b//a)-1])+"','close':'"+str(Cl[0])+"','max':'"+str(max(Ma))+"','min':'"+str(min(Mi))+"','time':"+str(t3)+"'}'\n")
    op.clear()
    cl.clear()
    ma.clear()
    mi.clear()
    f1.close()
    f2.close()
    print(str(b)+'MK-stored')
    
def startt(t1):
    i=0
    print('1')
    while True:
        t3=datetime.datetime.now()
        if t3>t1+space:
            t1=datetime.datetime.now()
            print(t3)
            five_second.append(get_price())
            if len(five_second)==12:
                w_onemk(t3)
                five_second.clear()
                i+=1
                if i%5==0:
                    w_mk(1,5,t3)
                if i%15==0:
                    w_mk(5,15,t3)
                if i%30==0:
                    w_mk(15,30,t3)
                if i%60==0:
                    w_mk(30,60,t3)
                if i%120==0:
                    w_mk(60,120,t3)


while True:
    t2=datetime.datetime.now()
    if t2.time()>=start and t2.time()<=stop:
        startt(t1)
        break
                
            
