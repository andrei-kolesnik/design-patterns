<?php
declare(strict_types=1);
/*
https://en.wikipedia.org/wiki/Composite_pattern
Composite composes objects into tree structures to represent part-whole hierarchies. 
Composite lets clients treat individual objects and compositions of objects uniformly.
*/
interface iVideo {
    public function contents() : string;
}

class Video implements iVideo {
    private $title;
    function __construct(string $title) { $this->title = $title; }
    public function contents() : string { return $this->title; }
}

class PlayList implements iVideo {
    private $title;
    private $list = array();
    function __construct(string $title) { $this->title = $title; }
    public function add(iVideo $video) { $this->list[] = $video; }
    public function contents() : string { 
        $result = $this->title;
        foreach ($this->list as $video) 
            $result .= " | " . $video->contents();
        return  $result;
    }
}

$pl1 = new PlayList("Creational");
$pl1->add(new Video("Singleton"));
$pl1->add(new Video("Factory Method"));

$pl2 = new PlayList("Behavioral");
$pl2->add(new Video("Observer"));
$pl2->add(new Video("Strategy"));

$pl3 = new PlayList("Structural");
$pl3->add(new Video("Bridge"));
$pl3->add(new Video("Decorator"));
$pl3->add(new Video("Proxy"));

$play = new PlayList("Design Patterns");
$play->add(new Video("Introduction"));
$play->add($pl1);
$play->add($pl2);
$play->add($pl3);

echo $play->contents();
