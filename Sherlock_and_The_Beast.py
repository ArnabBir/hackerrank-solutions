T=int(raw_input())
while(T):
    N=int(raw_input())
    count5 = N
    while(count5 % 3 != 0):
        z -= 5
    if(z < 0):
        print '-1'
    else:
        print count5 * '5' + (N - count5)*'3'
    T -= 1
