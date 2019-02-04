<?php
/*
Prorotype specifies the kinds of objects to create using a prototypical instance, 
and create new objects from the 'skeleton' of an existing object, 
thus boosting performance and keeping memory footprints to a minimum.
https://en.wikipedia.org/wiki/Prototype_pattern
*/
class RealPrototype {
    static $count;
    public $id;
    public $state;
    public function __construct($state) {
        $this->state = $state;
        $this->id = ++self::$count;
    }
    public function __clone() {
        $this->id = ++self::$count;
    }
    public function __toString() {
        return "ID: " . $this->id . " STATE: " . $this->state . " COUNT: " . self::$count . "\n";
    }
}

$original = new RealPrototype(100);
echo $original;
$copy = clone $original;
echo $copy;
$copy->state = 200;
echo $original;
echo $copy;
