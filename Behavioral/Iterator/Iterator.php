<?php
/*
https://en.wikipedia.org/wiki/Iterator_pattern
Iterator provides a way to access the elements of an aggregate object sequentially 
without exposing its underlying representation.

Example implementation: list the prime numbers in the given range
*/

interface iIterator {
    public function hasNext();
    public function nextItem();
    public function currentItem();
}

interface iIterable {
    public function getIterator();
}

class PrimeIterator {
    private $primes;
    private $pos = 0;

    public function __construct($primes) { $this->primes = $primes; }
// iIterator    
    public function hasNext() {
        return ($this->pos < $this->primes->count());
    }
    public function nextItem() {
        $this->pos++;
    }

    public function currentItem() {
        return $this->primes->getAt($this->pos);
    }
}

class Primes implements iIterable {
    private $primes = array();

    private function generate(int $limit): void {
        $Numb3rs = array_fill(0, $limit + 1, true);
        $Numb3rs[0] = $Numb3rs[1] = false;
        for ($i = 2; $i <= sqrt($limit); $i++)
        {
            if ($Numb3rs[$i])
                for ($j = $i * $i; $j <= $limit; $j += $i)
                {
                    $Numb3rs[$j] = false;
                }
        }
        for ($i = 2; $i <= $limit; $i++)
        {
            if ($Numb3rs[$i] !== false)
            $this->primes[] = $i;
        }
    }

    function __construct(int $limit) { 
        $this->generate($limit); 
    }

    public function count(): int { 
        return count($this->primes); 
    }

    public function getAt(int $i) {
        if ($i < $this->count())
            return $this->primes[$i];
        else
            return -1;
    }
// iIterable
    public function getIterator() {
        return new PrimeIterator($this);
    }
}

$primes = new Primes(100);
$it = $primes->getIterator();
while ($it->hasNext())
{
    echo $it->currentItem() . "\n";
    $it->nextItem();
}
