import numpy as np

def sigadd(n1,x1,n2,x2):
    nk=np.arange(min(min(n1),min(n2)), max(max(n1),max(n2))+1)
    N=len(nk)
    y1=np.zeros(N)
    y2=np.zeros(N)
    aa= abs(min(min(n1),min(n2)))
    n1=n1+aa
    n2=n2+aa
    y1[int(min(n1)):int(max(n1)+1)]=x1
    y2[int(min(n2)):int(max(n2)+1)]=x2
    y=y1+y2
    return nk,y,y1,y2


def sigmult(n1,x1,n2,x2):
    n=np.arange(min(min(n1),min(n2)), max(max(n1),max(n2))+1)
    N=len(n)
    y1=np.zeros(N)
    y2=np.zeros(N)
    aa= abs(min(min(n1),max(n1),min(n2),max(n2)))
    y1[int(min(n1)+aa):int(max(n1)+aa+1)]=x1
    y2[int(min(n2)+aa):int(max(n2)+aa+1)]=x2
    y=y1.T*y2
    return n,y,y1,y2

def sigshift(m,x,k):
    n=m+k
    y=x
    return n,y

def sigfold(n1,x1):
    N=len(n1)
    y=np.zeros(N)
    n=np.zeros(N)
    for i  in range(N):
        y[i]=x1[N-1-i]
        n[i]=-1*n1[N-1-i]
    return n,y


def impseq(n0,n1,n2):
    N=n2-n1+1
    n=np.arange(N)
    xn=np.zeros(N)
    for i in range(N):
        if (i+n1) == n0 : xn[i] = 1
    return xn
    
def stepseq(n0, n1, n2):
    N = n2 - n1 + 1
    n = np.arange(N)
    xn = np.zeros(N)
    for i in range(N):
        if (i + n1) >= n0 : xn[i] = 1
    return xn
#h(t)를 위해 추가한 함수
def stepseq1(n0, n1, n2):
    N = n2 - n1
    n = np.arange(N)
    xn = np.zeros(N)
    for i in range(N):
        if ((i + n1) >= n0):
            xn[i] = ((n1)*(-1)+(-i+300))*1
    return xn
#h(n)을 위해 추가한 함수
def stepseq2(n0, n1, n2):
    N = n2 - n1 + 1
    n = np.arange(N)
    xn = np.zeros(N)
    for i in range(N):
        if ((i + n1) >= n0):
            xn[i] = ((n1)*(-1)+(-i+3))*1
    return xn
#x(n)의 기수, 우수찾기
def evenodd(n,x):
    n1, xa = sigfold(n,x)
    n, xe, y1, y2 = sigadd(n, x, n1, xa)
    n, xo, y1, y2 = sigadd(n, x, n1, -xa)
    xe=xe/2
    xo=xo/2
    return n, xe, xo

def convolve_m(nx,x,nh,h):
    nyb = nx[0] + nh[0]
    nye = nx[len(x)-1]+nh[len(h)-1]
    ny = np.arange(nyb, nye+1)
    y = np.convolve(x,h)
    return ny,y

#y(t)를 위해 추가한 함수
def convolve_m1(t,xt,t2,ht):
    nyb = t[0]
    nye = t2[len(ht)-1]
    ny = np.arange(nyb-250, nye+839)/100
    y = np.convolve(xt/10,ht/10,mode='same')
    return ny,y