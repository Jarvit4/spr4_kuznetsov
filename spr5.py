#Product: Airplane
class Airplane:         
    def __init__(self):
        self.model = ""
        self.engine = ""
        self.wings = ""
        self.cabin = ""  

    def display(self):
        print(f"Model: {self.model}")
        print(f"Engine: {self.engine}")
        print(f"Wings: {self.wings}")
        print(f"Cabin: {self.cabin}")  
        print("_____________________")

#Builder
class AirplaneBuilder:
    def build_model(self):
        pass

    def build_engine(self):
        pass

    def build_wings(self):
        pass

    def build_cabin(self):  
        pass

    def get_result(self):
        pass

#Concrete Builder: PassengerAirplaneBuilder
class PassengerAirplaneBuilder(AirplaneBuilder):
    def __init__(self):
        self.airplane = Airplane()

    def build_model(self):
        self.airplane.model = "Passenger Airplane"

    def build_engine(self):
        self.airplane.engine = "Jet Engine"

    def build_wings(self):
        self.airplane.wings = "Large Wingspan"

    def build_cabin(self):
        self.airplane.cabin = "Comfortable Passenger Seats"  

    def get_result(self):
        return self.airplane

#Concrete Builder: CargoAirplaneBuilder
class CargoAirplaneBuilder(AirplaneBuilder):
    def __init__(self):
        self.airplane = Airplane()

    def build_model(self):
        self.airplane.model = "Cargo Airplane"

    def build_engine(self):
        self.airplane.engine = "Turboprop Engine"

    def build_wings(self):
        self.airplane.wings = "Heavy-Duty Wings"

    def build_cabin(self):
        self.airplane.cabin = "Cargo Hold"  

    def get_result(self):
        return self.airplane

#Director
class AirplaneDirector:
    def construct(self, builder):
        builder.build_model()
        builder.build_engine()
        builder.build_wings()
        builder.build_cabin()  
        return builder.get_result()

director = AirplaneDirector()

passenger_builder = PassengerAirplaneBuilder()
cargo_builder = CargoAirplaneBuilder()

passenger_airplane = director.construct(passenger_builder)
cargo_airplane = director.construct(cargo_builder)

passenger_airplane.display()
cargo_airplane.display()
