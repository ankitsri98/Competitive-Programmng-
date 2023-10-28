package com.personal.oops;

public class Earth {

    //This method is the entry point for all java applications
    public static void main(String args[]) {

        //Here we have created an object with the default constructor initially
        // values will be null and here are we assigning
        //alternative: we can also use parameterised constructor.
        Human tom;
        tom =  new Human();
        tom.age=5;
        tom.heightInInches=54;
        tom.eyeColour= "black";
        tom.name="ankit";
        tom.speak();
    }
}
