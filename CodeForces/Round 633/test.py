num1, num2 = input().split(' ')

num1 = int(num1)
num2 = int(num2)

endless = 10**9


def get_result(num1, num2):
    mul_num1 = num1
    mul_num2 = num2
    result = -1

    if(num1 == num2):
        print(-1)
        return
    else:
        for i in range(2, endless):
            mul_num1 = i*num1
            while(mul_num1 >= mul_num2 and mul_num1 * mul_num2 <= 10**18):
                if(mul_num1 != mul_num2):
                    result = mul_num1
                    print('Same!!!', mul_num1)
                    return
                mul_num2 = mul_num2 + num2
    # if no such number exists
    print(-1)
    return


get_result(num1, num2)