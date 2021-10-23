#!/usr/bin/python3
import sys
import subprocess

#setting a header for csv file
print("Enter your Header (Name of your store name or branch name)")
header = input()

#taking all the employee's name
def employeeNames():
    print("Enter employees name one by one and enter 'done' when you are finished")
    names = "pete"
    employeeArray = []
    while names != "done":
        print("Enter your employee's name")
        names = input()
        if names != "done":
            employeeArray.append(names)
        else:
            names = "done"
    return employeeArray

#combining shifts with employee
def employeeShift(employeeArray):
    print("Enter employee's shift and date with a comma inbetween (ex. 14:5,Friday)")
    i = 0
    resultArray = []
    while i < len(employeeArray):
        print("Employee Name: " + employeeArray[i])
        shift = ""
        while shift != "done":
            print("Enter date for the employee in all lower case letter and print 'done' when finished ex. monday")
            shift = input()
            if shift != "done":
                resultArray.append(shift)
        i += 1
    return resultArray
    
employeeArray = employeeNames()
result = employeeShift(employeeArray)



        
        