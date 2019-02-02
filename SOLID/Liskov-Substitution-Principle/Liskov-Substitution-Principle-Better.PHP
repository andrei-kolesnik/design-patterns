<?php
/*
Liskov's Substitution Principle
https://en.wikipedia.org/wiki/Liskov_substitution_principle
Derived classes must be substitutable for their base classes
*/
interface iFly {
    public function fly();
}

interface iMakeSound {
    public function makeSound();
}

class Bird {
    public $name;
    function __construct($name) { $this->name = $name; }
    public function __toString() { return $this->name . ": "; }
}

abstract class FlyingBird extends Bird implements iFly {
    public function fly() { echo $this, "Flying!\n"; }
}

class Duck extends FlyingBird implements iMakeSound {
    function __construct() { 
        parent::__construct("Duck");
    }
    public function makeSound() { echo $this, "Quack!\n"; }
}

class Ostrich extends Bird implements iMakeSound {
    function __construct() { 
        parent::__construct("Ostrich");
    }
    public function makeSound() { echo $this, "Chirp!\n"; }
}

$flock = array();
$flock[] = new Duck();
$flock[] = new Ostrich();

foreach($flock as $bird)
{
    if ($bird instanceof iFly) $bird->fly(); 
    if ($bird instanceof iMakeSound) $bird->makeSound();
}