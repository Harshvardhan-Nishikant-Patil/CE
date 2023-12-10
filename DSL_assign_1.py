student = []
n = int (input("enter the total number of students: "))
for i in range (n):
    std = int(input("enter roll number of student: "))
    student.append(std)
print("total students: ",student)


cricket = []
n = int (input("enter tatal number of students who play cricket: "))
for i in range (n):
    cric = int(input("enter roll number of student who play cricket: "))
    cricket.append(cric)
print("students who play cricket",cricket)


football = []
n = int (input("enter the total number of students who play football: "))
for i in range (n):
    foot = int(input("enter roll number of student who play football: "))
    football.append(foot)
print("student who play football",football)



badminton = []
n = int (input("enter the total number of students who play badminton: "))
for i in range (n):
    bad = int(input("enter roll number of student who play badminton: "))
    badminton.append(bad)
print("students who play badminton",badminton)


def cricket_or_badminton():
    cric_bad = []
    for i in cricket:
        cric_bad += [i]
    for i in badminton:
        if i not in cricket:
            cric_bad += [i]
    return cric_bad




def either_cric_or_bad(cricket , badminton):
    ecob = []
    for i in cricket:
        if i not in badminton:
            ecob += [i]

    for i in badminton:
        if i not in cricket:
            ecob += [i]
    
    return ecob




def neither_cric_nor_bad(cricket , badminton):
    ncnb = []
    for i in student:
        if i not in cricket:
            if i not in badminton:
                ncnb += [i]
    return ncnb



def cricket_and_football_not_badminton(cricket,badminton,football):
    cafnb = []
    for i in cricket:
        if i in football:
            if i not in badminton:
                cafnb += [i]
    return cafnb




print("""
1.students who play cricket and badminton
2.students who play either cricket or badminton but not both
3.students who play neither cricket nor badminton
4.students who play cricket and cricket and football but not badminton
0.stop getting output
""")

while(True):
    choice = int(input("enter your choice: "))

    if (choice==1):
        print("students who play cricket or badminton are: ",cricket_or_badminton())
    
    elif (choice == 2):
        print("Students who play either cricket or badminton but not both:",either_cric_or_bad(cricket,badminton))

    elif (choice == 3):
        print("students who play neither cricket not badminton: ",neither_cric_nor_bad(cricket , badminton))

    elif (choice == 4):
        print("studnets who play cricket and football but not badminton: ",cricket_and_football_not_badminton(cricket,badminton,football))

    elif(choice == 0):
        break

    else:
        print("enter valid choice")