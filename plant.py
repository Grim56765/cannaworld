import random

def clamp(value):
    return max(0,min(255, value))

def rgb_to_hex(r, g, b):
    return "#{:02X}{:02X}{:02X}".format(r, g, b)

class LandraceGene:
    def __init__(self):
        self.gS_lower = random.randint(8, 12)
        self.gS_higher = random.randint(13, 20)
        
        self.y_lower = random.randint(8, 32)
        self.y_higher = random.randint(33, 48)
        
        self.redBias = random.randint(0, 255)
        self.greenBias = random.randint(0, 255)
        self.blueBias = random.randint(0, 255)

class Plant:
    def __init__(self, LandraceGene):
        self.lrg = LandraceGene
        
        self.plantGrowthSpeed = random.randint(self.lrg.gS_lower, self.lrg.gS_higher)
        self.plantYield = random.randint(self.lrg.y_lower, self.lrg.y_higher)
        
        r = clamp(self.lrg.greenBias + random.randint(-30, 30))
        g = clamp(self.lrg.redBias + random.randint(-30, 30))
        b = clamp(self.lrg.blueBias + random.randint(-30, 30))
        
        self.color = rgb_to_hex(r, g, b)
        
        self.gender = random.randint(1, 100)
        if self.gender > 51:
            self.gender = "M"
        else:
            self.gender = "F"
    
if __name__ == "__main__":
    
    clemmonsLrg = LandraceGene()
    print("=== Clemmons Genetic Line ===\n")
    
    for i in range(5):
        plant = Plant(clemmonsLrg)
        
        print(f"Plant {i+1}")
        print(plant.plantGrowthSpeed, "Weeks")
        print(plant.plantYield, "Ounces")
        print(plant.color)
        print(plant.gender)
        print()

