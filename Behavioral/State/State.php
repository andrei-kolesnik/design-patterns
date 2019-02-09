<?php
/*
https://en.wikipedia.org/wiki/State_pattern
State allows an object to alter its behavior when its internal state changes. 
The object will appear to change its class.
*/

abstract class VendingMachineState {
    protected $machine;
    public function __construct($machine) { $this->machine = $machine; }
    abstract public function addMoney($money);
    abstract public function getProduct();
}

class VendingMachineStateWaiting extends VendingMachineState {
    public function __toString() { return "STATE: Waiting...\n"; }
    
    public function addMoney($money) {
        $this->machine->deposited += $money;
        echo "Deposited: $" . $money . " ($" . $this->machine->deposited . " total)\n";
        if ($this->machine->deposited >= $this->machine->price) {
            $this->machine->setState(new VendingMachineStatePaid($this->machine));
        }
    }

    public function getProduct() {
        echo "Deposite $" . ($this->machine->price - $this->machine->deposited) . " more\n" ;
    }
}

class VendingMachineStatePaid extends VendingMachineState {
    public function __toString() { return "STATE: Paid...\n"; }

    public function addMoney($money) {
        echo "Paid in full already...\n";
        $this->machine->deposited += $money;
    }

    public function getProduct() {
        echo "Here is your product\n" ;
        $this->machine->deposited -= $this->machine->price;
        if ($this->machine->deposited > 0) {
            echo "Here is your change $" . $this->machine->deposited . "\n" ;
            $this->machine->deposited = 0;
        }
        $this->machine->setState(new VendingMachineStateWaiting($this->machine));
    }
}

class VendingMachine {
    private $state;
    public $price;
    public $deposited;
    public function __construct($price) { 
        $this->price = $price; 
        $this->deposited = 0;
        $this->setState(new VendingMachineStateWaiting($this));
    }
    public function deposit($money) { $this->state->addMoney($money); }
    public function deploy() { $this->state->getProduct(); }
    public function setState($state) { 
        $this->state = $state; 
        echo $this->state;
    }
}

$vm = new VendingMachine(20);
$vm->deploy();
$vm->deposit(10);
$vm->deploy();
$vm->deposit(5);
$vm->deploy();
$vm->deposit(10);
$vm->deploy();
$vm->deposit(20);
$vm->deploy();
