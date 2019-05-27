<?php
/*
https://en.wikipedia.org/wiki/Flyweight_pattern
Use sharing to support large numbers of similar objects efficiently.
*/
abstract class Tile {
    function __construct() {
        print("Tile constructor called\n");
    }
    // intrinsic (invariant) state that can be shared
    protected $pattern = [
        [1, 0, 0, 0, 1],
        [0, 1, 0, 1, 0],
        [0, 0, 1, 0, 0],
        [0, 1, 0, 1, 0],
        [1, 0, 0, 0, 1],
    ];
    abstract public function draw(string $letter); // extrinsic (variant) state can be passed in
}

class ConcreteTile extends Tile {
    public function draw(string $letter) {
        foreach ($this->pattern as $row) {
            foreach ($row as $cell) {
                print($cell ? $letter : ' ');
            }
            print("\n");
        }
    }
}

class TileFactory {
    private $theTile;
    function __construct() {
        $this->theTile = new ConcreteTile();
    }
    function getTile(): Tile {
        return $this->theTile;
    }
}

$factory = new TileFactory();
foreach(range('a', 'e') as $letter) {
    $factory->getTile()->draw($letter);
}
