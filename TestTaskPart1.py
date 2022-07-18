# Create empty dictionary
SymbolDict = {}
# Read input string
InputString = list(input().lower())
# For every char in input string
for Index, Char in enumerate(InputString):
    # If char wasn't met yet
    if Char not in SymbolDict.keys():
        # Add its position to dictionary and change to "("
        SymbolDict[Char] = Index
        InputString[Index] = "("
    # If it was met before
    else:
        # Change first entry to ")" if it isn't already 
        if InputString[SymbolDict[Char]] != ")":
            InputString[SymbolDict[Char]] = ")"
        # Change current char to ")"
        InputString[Index] = ")"

# Print result string
print("".join(InputString))