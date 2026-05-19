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
        
        self.hiddenRedBias = random.randint(0, 255)
        self.hiddenGreenBias = random.randint(0, 255)
        self.hiddenBlueBias = random.randint(0, 255)
        

class Plant:
    def __init__(self, LandraceGene):
        self.lrg = LandraceGene
        
        self.plantGrowthSpeed = random.randint(self.lrg.gS_lower, self.lrg.gS_higher)
        self.plantYield = random.randint(self.lrg.y_lower, self.lrg.y_higher)
       
        ###Color###
        baseR = 50
        baseG = 100
        baseB = 50  
                
        variation = random.randint(-25, 25)          # tweak this number for more/less variation
        r = clamp(self.lrg.hiddenRedBias + variation)
        g = clamp(self.lrg.hiddenGreenBias + variation)
        b = clamp(self.lrg.hiddenBlueBias + variation)
                
        self.color = rgb_to_hex(baseR, baseG, baseB)
        self.hiddenColor = rgb_to_hex(r, g, b)
        self.expressionStrength = random.randint(1, 10) #max is 100
        
        self.colorChancePercent = random.randint(1, 100)
        if self.colorChancePercent <= 20:
            self.colorExpressed = f"Color is expressed (strength: {self.expressionStrength})"
        else:
            self.colorExpressed = "Color is not expressed"
            
        
        #when breeding, if parent has color - raise chance of color
        
        ###Gender###
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
        print("Color: ", plant.color)
        print("Hidden Color: ",plant.hiddenColor)
        print(plant.colorExpressed)
        print(plant.gender)
        print()

