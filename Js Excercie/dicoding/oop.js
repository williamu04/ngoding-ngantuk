/**
 * TODO:
 * 1. Buatlah class bernama Animal dengan ketentuan:
 *    - Memiliki properti:
 *      - name: string
 *      - age: int
 *      - isMammal: boolean
 *    - Memiliki constructor untuk menginisialisasi properti:
 *      - name
 *      - age
 *      - isMammal
 * 2. Buatlah class bernama Rabbit dengan ketentuan:
 *    - Merupakan turunan dari class Animal
 *    - Memiliki method:
 *      - eat yang mengembalikan nilai string `${this.name} sedang makan!`
 *    - Ketika diinstansiasi, properti isMammal harus bernilai true
 * 3. Buatlah class bernama Eagle dengan ketentuan:
 *    - Merupakan turunan dari class Animal
 *    - Memiliki method:
 *      - fly yang mengembalikan nilai string `${this.name} sedang terbang!`
 *    - Ketika diinstansiasi, properti isMammal harus bernilai false
 * 4. Buatlah instance dari class Rabbit bernama "myRabbit" dengan ketentuan:
 *    - properti name bernilai: "Labi"
 *    - properti age bernilai: 2
 * 5. Buatlah instance dari class Eagle bernama "myEagle" dengan ketentuan:
 *    - properti name bernilai: "Elo"
 *    - properti age bernilai: 4
 */

// Tulis kode di bawah ini

// Define the Animal class
class Animal {
    constructor(name, age, isMammal) {
      this.name = name;
      this.age = age;
      this.isMammal = isMammal;
    }
  }
  
  // Define the Rabbit class as a subclass of Animal
  class Rabbit extends Animal {
    constructor(name, age) {
      super(name, age, true); // Rabbits are mammals
    }
  
    eat() {
      return `${this.name} sedang makan!`;
    }
  }
  
  // Define the Eagle class as a subclass of Animal
  class Eagle extends Animal {
    constructor(name, age) {
      super(name, age, false); // Eagles are not mammals
    }
  
    fly() {
      return `${this.name} sedang terbang!`;
    }
  }
  
  // Create an instance of Rabbit named "myRabbit"
  const myRabbit = new Rabbit("Labi", 2);
  
  // Create an instance of Eagle named "myEagle"
  const myEagle = new Eagle("Elo", 4);
  