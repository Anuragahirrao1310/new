class AnimalShelter:
    def __init__(self):
        self.cats = []  # List to hold cats
        self.dogs = []  # List to hold dogs
        self.rabbits = []  # List to hold rabbits
        self.admission_time = 0  # Variable to track admission time

    def new_entry(self, animal_type):
        """
        Add a new animal to the shelter with the current admission time.
        """
        self.admission_time += 1
        animal = {"type": animal_type, "admission_time": self.admission_time}
        if animal_type == "cat":
            self.cats.append(animal)
        elif animal_type == "dog":
            self.dogs.append(animal)
        elif animal_type == "rabbit":
            self.rabbits.append(animal)
        else:
            print("Invalid animal type")

    def adopt_dog(self):
        """
        Adopt the dog that has been in the shelter the longest.
        """
        if self.dogs:
            dog_to_adopt = min(self.dogs, key=lambda x: x["admission_time"])
            self.dogs.remove(dog_to_adopt)
            return dog_to_adopt
        else:
            return "No dogs available for adoption."

    def adopt_cat(self):
        """
        Adopt the cat that has been in the shelter the longest.
        """
        if self.cats:
            cat_to_adopt = min(self.cats, key=lambda x: x["admission_time"])
            self.cats.remove(cat_to_adopt)
            return cat_to_adopt
        else:
            return "No cats available for adoption."

    def adopt_rabbit(self):
        """
        Adopt the rabbit that has been in the shelter the longest.
        """
        if self.rabbits:
            rabbit_to_adopt = min(self.rabbits, key=lambda x: x["admission_time"])
            self.rabbits.remove(rabbit_to_adopt)
            return rabbit_to_adopt
        else:
            return "No rabbits available for adoption."

    def adopt_any(self):
        """
        Adopt any animal that has been in the shelter the longest.
        """
        all_animals = self.cats + self.dogs + self.rabbits
        if all_animals:
            animal_to_adopt = min(all_animals, key=lambda x: x["admission_time"])
            if animal_to_adopt in self.cats:
                self.cats.remove(animal_to_adopt)
            elif animal_to_adopt in self.dogs:
                self.dogs.remove(animal_to_adopt)
            else:
                self.rabbits.remove(animal_to_adopt)
            return animal_to_adopt
        else:
            return "No animals available for adoption."

    def display_info(self):
        """
        Display the information about animals in the shelter.
        """
        print("Cats in the shelter:", [cat["admission_time"] for cat in self.cats])
        print("Dogs in the shelter:", [dog["admission_time"] for dog in self.dogs])
        print("Rabbits in the shelter:", [rabbit["admission_time"] for rabbit in self.rabbits])

# Example usage
shelter = AnimalShelter()

shelter.new_entry("cat")
shelter.new_entry("dog")
shelter.new_entry("rabbit")
shelter.new_entry("cat")

print("Shelter Information:")
shelter.display_info()

adopted_cat = shelter.adopt_cat()
adopted_dog = shelter.adopt_dog()
adopted_any = shelter.adopt_any()

print("\nAdopted Cat:", adopted_cat)
print("Adopted Dog:", adopted_dog)
print("Adopted Any Animal:", adopted_any)

print("\nUpdated Shelter Information:")
shelter.display_info()
