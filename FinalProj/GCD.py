def main():
    x = Euclidean_GCD(40, 15)
    print("Euclidean_GCD is: ", x)
    y = NoName_GCD(40, 15)
    print("NoName_GCD is: ", y)

def Euclidean_GCD(x, y):
    if y > 0:
        temp_x = x;
        x = y;
        y = temp_x % y
        return Euclidean_GCD(x, y)
    else:
        return x
    
def NoName_GCD(x, y):
    if (y > x):
        temp = y
        y = x
        x = temp
        
    if (x == y):
        return x
    
    elif ((x%2) == 0 and (y%2) == 0):
        return (2 * NoName_GCD((x/2), (y/2)))
    
    elif ((x%2) != 0 and (y%2) == 0):
        return (NoName_GCD(x, (y/2)))
            
    elif ((x%2) == 0 and (y%2) != 0):
        return (NoName_GCD((x/2), y))
    
    elif ((x%2) != 0 and (y%2) != 0):
        return (NoName_GCD((x-y), y))   
    

main()