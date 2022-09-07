from py_compile import main

# Have to write in Python for future implmentation (from C++ so fun)
# Fucking kill me
class Card:
    def __init__(self, quantity, name):
        self.quantity = quantity
        self.name = name
    
    def getName(self):
        return self.name

    def getQuantity(self):
        return self.quantity




def searchList(cardList, cardName):
    for card in cardList:
        if card.getName().lower() == cardName.lower():
            return True
    return False

def loadList():
    # Returns list of card names (strings)
    cardList = []
    fileName = "Test Files/" + input("What is the file?")
    file = open(fileName, "r")
    
    for card in file:
        quantity = 0
        name = ""
        for s in card.split():
            if str(s).isdigit():
                quantity = int(s)
            else:
                name = name + s + " "
        
        c = Card(quantity, name)
        
        cardList.append(c)

    file.close()

    return cardList


def printList(cardList):
    for card in cardList:
        print(card.getName())
        

if __name__ == "__main__":
    cards = []
    menuOption = ""
    print("Hello World")

    cards = loadList()

    while menuOption != "3":
        print("What do you want to do")
        print("1. Print Deck List")
        print("2. Find Card in Deck List")
        print("3. Quit")

        menuOption = input()

        match menuOption:
            case "1":
                printList(cards)
            case "2":
                cardName = ""
                cardName = input("What card are you looking for? ")
                if (searchList(cards, cardName)):
                    print("Card is in the list")
                else:
                    print("Card is not in the list")
            case _:
                print("Please try again")


