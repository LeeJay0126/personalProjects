#!/usr/bin/python3
import sys
import subprocess

print("Enter your Header (Name of your store name or branch name)")
header = input()

def employeeNames():
    print("Enter employees name one by one and enter 'done' when you are finished")
    names = "pete"
    employeeArray = []
    while names != "done":
        print("Enter your employee's name")
        names = input()
        employeeArray.append(names)
    return employeeArray
    
def employeeShift(employeeArray):
    print("Enter employee's shift and date with a comma inbetween (ex. 14:5,Friday)")
    i = 0
    resultArray = []
    validator = 0
    while i < len(employeeArray):
        k = 0
        print("Employee Name: " + employeeArray[i])
        shift = ""
        while shift != "done":
            print("Enter date for the employee in all lower case letter ex. monday")
            shift = input()
            
            
            

    return resultArray
    
employeeArray = employeeNames()
result = employeeShift(employeeArray)

i = 0
while i < len(result):
    print(result[i])

        
        