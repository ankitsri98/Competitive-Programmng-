package com.personal.oops;

public class Earth {

    //This method is the entry point for all java applications
    public static void main(String args[]) {

        //Here we have created an object with the parameterised constructor initially
        Human tom; //here tom is a variable : it is also called instance or object variable.
        tom =  new Human("Ankit",12,54,"black"); //and here its become object basically new Human is the object.
        tom.speak();
    }
}
