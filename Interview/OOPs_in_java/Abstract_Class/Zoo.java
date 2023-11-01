package com.personal.oops;

public class Zoo {
    public static void main(String[] arg) {

       /*
       Abstract class :  can only be extented and never Instantiated
        */
        Fish f = new Fish(1,"m",13);
        f.move();

        Bird b = new Bird(1, "f", 21);
        b.move();

        /*
        This is possible
        Animal f = new Fish(1,"m",13);
        f.move();

        Animal b = new Bird(1, "f", 21);
        b.move();

        Here instance variable is of Animal type but it points to Fish and bird. ALSO F. ALLOWS ONLY METHODS WRITTEN IN ANIMAL CALL EVEN IF OBJECT IS OF FISH OR BIRD IT CAN'T CALL FISH BIRD CLASS METHOD

        This is not possible 
        Animal f = new Animal(1,"m",13);
        f.move();

        Animal b = new Animal(1, "f", 21);
        b.move();

         */
    }
}
