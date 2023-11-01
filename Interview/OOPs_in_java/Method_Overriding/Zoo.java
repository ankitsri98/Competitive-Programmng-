package com.personal.oops;

public class Zoo {
    public static void main(String[] arg) {

       /*
       There are 2 classes 1. sparrow and 2. chicken
       1. can fly
       2. cannot fly
       and there is a class Bird which is inherited by these 2 classes as these are birds.
       Birds has a fly method which is not applicable to both child classes.

       1st Method is to Override the Method Fly
       2nd is interface
        */

        Chicken chick = new Chicken(1,"m",12);
        chick.fly();
    }
}
