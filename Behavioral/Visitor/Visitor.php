<?php
/*
Visitor lets a new operation be defined without changing the classes of the elements on which it operates.
Visitor separates an algorithm from an object structure by moving the hierarchy of methods into one object.
https://en.wikipedia.org/wiki/Visitor_pattern
*/

// Abstract Visitable
interface IVisitable {
	// Accepts any IVisitor
	public function accept(IVisitor $visitor): void;
}

// Parent class for applications
class BaseApplication  {
	/** @var int */
	protected $price;
	/** @var string */
	protected $name;

	public function getPrice(): int {
		return $this->price;
	}
	public function getName(): string {
		return $this->name;
	}
	public function display(): void {
		print($this->name . " price is " . $this->price . "\n");
	}
};

// Concrete Visitable #1	
class FreeApplication extends BaseApplication implements IVisitable {
	public function __construct() {
		$this->price = 0;
		$this->name = "Free App";
	}
	public function accept(IVisitor $visitor): void {
		$visitor->visitFree($this);
	}
};

// Concrete Visitable #2
class ProApplication extends BaseApplication implements IVisitable {
	public function __construct() {
		$this->price = 20;
		$this->name = "Pro App";
	}
	public function accept(IVisitor $visitor): void {
		$visitor->visitPro($this);
	}
};

// Concrete Visitable #3	
class EnterpriseApplication extends BaseApplication implements IVisitable {
	public function __construct() {
		$this->price = 100;
		$this->name = "Enterprise App";
	}
	public function accept(IVisitor $visitor): void {
		$visitor->visitEnterprise($this);
	}
};

// Abstract Visitor
interface IVisitor {
	// Overloads for all kinds of IVisitable
	public function visitFree(FreeApplication $app): void;
	public function visitPro(ProApplication $app): void;
	public function visitEnterprise(EnterpriseApplication $app): void;
}

// Parent class for offers
class BaseOffer {
	/** @var string */
	protected $name;

	public function display(string $appName, int $appPrice): void {
		print($this->name . ": $appName price is $appPrice\n");
	}
};

// Concrete Visitor #1
class SignupOffer extends BaseOffer implements IVisitor {
	public function __construct() {
		$this->name = "Signup Offer";
	}
	public function visitFree(FreeApplication $app): void {
		$this->display($app->getName(), $app->getPrice());
	}
	public function visitPro(ProApplication $app): void {		
		$this->display($app->getName(), $app->getPrice() - 2);
	}
	public function visitEnterprise(EnterpriseApplication $app): void {
		$this->display($app->getName(), $app->getPrice() / 10 * 8);
	}
};

// Concrete Visitor #2
class SaleOffer extends BaseOffer implements IVisitor {
	public function __construct() {
		$this->name = "Holiday Sale";
	}
	public function visitFree(FreeApplication $app): void {
		$this->display($app->getName(), $app->getPrice());
	}
	public function visitPro(ProApplication $app): void {
		$this->display($app->getName(), $app->getPrice() - 5);
	}
	public function visitEnterprise(EnterpriseApplication $app): void {
		$this->display($app->getName(), $app->getPrice() / 2);
	}
};

$freeApp = new FreeApplication;
$proApp  = new ProApplication;
$entApp  = new EnterpriseApplication;

$signup = new SignupOffer;
$sale   = new SaleOffer;

$freeApp->display();
$proApp->display();
$entApp->display();

$freeApp->accept($signup);
$proApp->accept($signup);;
$entApp->accept($signup);;

$freeApp->accept($sale);
$proApp->accept($sale);
$entApp->accept($sale);
