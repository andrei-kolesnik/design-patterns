# [Design Patterns](https://en.wikipedia.org/wiki/Software_design_pattern)

## Creational
| Pattern | Description | Source Code |
| :--- | :--- | :---: |
|[Abstract Factory](https://en.wikipedia.org/wiki/Abstract_factory_pattern)|Provide an interface for creating families of related or dependent objects without specifying their concrete classes.|[C++](Creational/Abstract-factory) [Delphi](Creational/Abstract-factory/Delphi)|
|[Factory Method](https://en.wikipedia.org/wiki/Factory_method_pattern)|Define an interface for creating a single object, but let subclasses decide which class to instantiate.|[C++](Creational/Factory-method) |
|[Prototype](https://en.wikipedia.org/wiki/Prototype_pattern)|Specify the kinds of objects to create using a prototypical instance, and create new objects from the 'skeleton' of an existing object, thus boosting performance and keeping memory footprints to a minimum.|[C++](Creational/Prototype)
|[Singleton](https://en.wikipedia.org/wiki/Singleton_patternn)|Ensure a class has only one instance, and provide a global point of access to it.|[C++](Creational/Singleton) [Delphi](Creational/Singleton/Delphi) |

## Behavioral
| Pattern | Description | Source Code |
| :--- | :--- | :---: |
|[Command](https://en.wikipedia.org/wiki/Command_pattern)|Encapsulate a request as an object, thereby allowing for the parameterization of clients with different requests, and the queuing or logging of requests.|[C++](Behavioral/Command)|
|[Observer](https://en.wikipedia.org/wiki/Observer_pattern)|Define a one-to-many dependency between objects where a state change in one object results in all its dependents being notified and updated automatically.|[C++](Behavioral/Observer)|
|[Strategy](https://en.wikipedia.org/wiki/Strategy_pattern)|Define a family of algorithms, encapsulate each one, and make them interchangeable.|[C++](Behavioral/Strategy)|

<!--
|[Template](https://en.wikipedia.org/wiki/Template_method_pattern)|Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.|[C++](Behavioral/Strategy)|
-->

## Structural
| Pattern | Description | Source Code |
| :--- | :--- | :---: |
|[Adapter](https://en.wikipedia.org/wiki/Adapter_pattern)|Convert the interface of a class into another interface clients expect.|[C++](Structural/Adapter)|
|[Bridge](https://en.wikipedia.org/wiki/Bridge_pattern)|Decouple an abstraction from its implementation allowing the two to vary independently.|[C++](Structural/Bridge)|
|[Decorator](https://en.wikipedia.org/wiki/Decorator_pattern)|Attach additional responsibilities to an object dynamically keeping the same interface.|[C++](Structural/Decorator)|
|[Facade](https://en.wikipedia.org/wiki/Facade_pattern)|Provide a unified interface to a set of interfaces in a subsystem.|[C++](Structural/Facade)|
|[Proxy](https://en.wikipedia.org/wiki/Proxy_pattern)|Provide a surrogate or placeholder for another object to control access to it.|[C++](Structural/Proxy)|

----

# [S.O.L.I.D.](https://en.wikipedia.org/wiki/SOLID) principles of object-oriented programming

| Principle | Description | Source Code |
| :--- | :--- | :---: |
|[Single Responsibility Principle](https://en.wikipedia.org/wiki/Single_responsibility_principle)|A class should have only a single responsibility (reason to change)|[C++](SOLID/Single-Responsibility-Principle)|
|[Open/closed principle](https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle)|Classes should be open for extension, but closed for modification|[C++<br/> PHP](SOLID/Open-Closed-Principle)|
|[Liskov's Substitution Principle](https://en.wikipedia.org/wiki/Liskov_substitution_principle)|Derived classes must be substitutable for their base classes|[C++](SOLID/Liskov-Substitution-Principle)|
|[Interface segregation principle](https://en.wikipedia.org/wiki/Interface_segregation_principle)|Many client-specific interfaces are better than one general-purpose interface|[C++](SOLID/Interface-Segregation-Principle)|
|[Dependency inversion principle](https://en.wikipedia.org/wiki/Dependency_inversion_principle)|Depend upon abstractions, not concretions|[C++](SOLID/Dependency-Inversion-Principle)|