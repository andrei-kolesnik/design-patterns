<?php
abstract class Shape {
    public $name;
    function __construct($name) { $this->name = $name; }
    public function __toString() { return $this->name . ": "; }
    abstract protected function area();
}

class Rectangle extends Shape {
    public $width, $height;
    function __construct($width, $height) { 
        parent::__construct("Rectangle");
        $this->width = $width; 
        $this->height = $height; 
    }
    public function __toString() { 
        return parent::__toString() . $this->width . " x " . $this->height; 
    }
    public function area() {
        return $this->width * $this->height;    
    }
}

class Circle extends Shape {
    public $radius;
    function __construct($radius) {
        parent::__construct("Circle");
        $this->radius = $radius;
    }
    public function __toString() { 
        return parent::__toString() . "R " . $this->radius; 
    }
    public function area() {
        return $this->radius ** 2 * M_PI;    
    }
}

class Shapes {
    private $shapes = array();
    public function add($shape) {
        $this->shapes[] = $shape;
    }
    public function totalArea() {
        $area = 0;
        foreach ($this->shapes as $shape)
            //Good: no need to change this every time a new shape is introduced
            $area += $shape->area();
        return $area;
    }
}

$shapes = new Shapes();
$shapes->add(new Rectangle(2, 3));
$shapes->add(new Rectangle(3, 4));
$shapes->add(new Rectangle(4, 5));
$shapes->add(new Circle(4));
$shapes->add(new Circle(5));
echo round($shapes->totalArea(), 2);