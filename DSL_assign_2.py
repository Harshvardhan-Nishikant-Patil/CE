main_string = str(input("Enter the string: "))
list = main_string.split()


def longest_word(main_string):
    list = main_string.split()
    count = 0
    max_count = 0
    for i in list:
        for j in i:
            count = count +1
        if count>max_count:
            max_count = count
            word = i
        count = 0
    print("the longest word in string is: ",word)



def char_occurance(main_string):
    character = input("enter character: ")
    count = 0
    for i in main_string:
        if (i == character):
            count = count + 1
    print("occurance of", character, "in string is", count, "times")


def palindrome(main_string):
    count = 0
    S=""
    for i in main_string:
        count += 1
    for j in range(count-1,-1,-1):
        S += main_string[j]
    if(main_string==S):
        print("String is palindrome")
    else:
        print("String is not palindrome")
    
def find_first_occurrence(main_string):
    substring = input("Enter the substring to search for: ")
    index = main_string.find(substring)
    print("occurance of",substring,"is at position: ",index)


                

def word_occurance(main_string):
    data = dict()
    list = main_string.split()
    for word in list:
        if word in data:
            data[word] +=1
        else:
            data[word] = 1
    return data


while(True):
    print('''Select the respective option for result
          Enter 1 to find longest word in the string
          Enter 2 to find frequency of occurance of particular character
          Enter 3 to find string is palindrom or not
          Enter 4 to find index of first appearance of substring
          Enter 5 to count the occurance of word in string
          Enter 6 to stop getting the result''')

    choice = int(input("Enter your choice no :"))

    if (choice == 1):
        longest_word(main_string)

    elif (choice == 2):
        char_occurance(main_string)

    elif (choice == 3):
        palindrome(main_string)

    elif (choice == 4):
        (find_first_occurrence(main_string))
    
    elif (choice == 5):
        print(word_occurance(main_string))
    
    else:
        print("Enter valid option no.")
        break