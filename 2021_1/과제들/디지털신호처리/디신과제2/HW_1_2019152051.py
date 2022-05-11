import numpy as np
import matplotlib.pylab as plt
from scipy import signal
from scipy.interpolate import *
from ch03_module import *

#x(t)
dt = 1/100
t = np.arange(-400,700)*dt
xt = stepseq(-200,-400,699) - stepseq(200,-400,699) 

#h(t)
ht = stepseq1(0,-400,700)*dt - stepseq1(300,-400,700)*dt

#y(t)
nt,yt = convolve_m1(t,xt,t,ht)


#x(n) , h(n), y(n)    
n = np.arange(-4, 7)
xn = stepseq(-2,-4,6) - stepseq(3,-4,6)
hn = stepseq2(0,-4,6) - stepseq2(3,-4,6)
n1,y = convolve_m(n,xn,n,hn)


plt.figure(1)
plt.subplot(3,1,1); plt.plot(t, xt, "blue"); plt.grid()
plt.xlim(-5,7); plt.ylabel("x(t)")
plt.subplot(3,1,2); plt.plot(t, ht, "blue"); plt.grid()
plt.xlim(-5,7); plt.ylabel("h(t)")
plt.subplot(3,1,3); plt.plot(nt, yt, "blue"); plt.grid()
plt.xlim(-5,7); plt.ylabel("y(t)")

plt.figure(2)
plt.subplot(3,1,1); plt.stem(n, xn, "blue"); plt.grid(); plt.ylabel("x(n)")
plt.subplot(3,1,2); plt.stem(n, hn, "blue"); plt.grid(); plt.ylabel("h(n)")
plt.subplot(3,1,3); plt.stem(n1, y, "blue"); plt.grid(); 
plt.xlim(-5,7); plt.ylabel("y(n)")


