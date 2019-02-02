<?php
/*
Liskov's Substitution Principle
https://en.wikipedia.org/wiki/Liskov_substitution_principle
Derived classes must be substitutable for their base classes
*/
abstract class Bird {
    public $name;
    function __construct($name) { $this->name = $name; }
    public function __toString() { return $this->name . ": "; }
    abstract public function makeSound();
}

abstract class FlyingBird extends Bird {
    public function fly() { echo $this, "Flying!\n"; }
}

class Duck extends FlyingBird {
    function __construct() { 
        parent::__construct("Duck");
    }
    public function makeSound() { echo $this, "Quack!\n"; }
}

class Ostrich extends Bird {
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
    if ($bird instanceof FlyingBird) $bird->fly(); 
    $bird->makeSound();
}