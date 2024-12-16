#-cryptarithmetic puzzles


from itertools import permutations


def send_more_money():
    equation = ["SEND", "MORE", "MONEY"]
    chars = sorted(set(''.join(equation)))  


    print(f"\nUnique characters: {chars}")
   
    for perm in permutations(range(10), len(chars)):
        char_to_digit = dict(zip(chars, perm))
       
        def word_to_number(word):
            return int(''.join(str(char_to_digit[char]) for char in word))
       
        SEND = word_to_number("SEND")
        MORE = word_to_number("MORE")
        MONEY = word_to_number("MONEY")
       
        if SEND + MORE == MONEY:
            if char_to_digit['S'] != 0 and char_to_digit['M'] != 0:
                print(f"Solution found: SEND = {SEND}, MORE = {MORE}, MONEY = {MONEY}")
                print("Character to digit mapping:")
                for char, digit in char_to_digit.items():
                  print(f"{char} = {digit}")
                return char_to_digit
   
    return print("No solution found.")  


def logic_prolog():
    equation = ["LOGIC", "PROLOG"]
    chars = sorted(set(''.join(equation)))  


    print(f"\nUnique characters: {chars}")
   
    for perm in permutations(range(10), len(chars)):
        char_to_digit = dict(zip(chars, perm))
       
        def word_to_number(word):
            return int(''.join(str(char_to_digit[char]) for char in word))
       
        LOGIC = word_to_number("LOGIC")
        PROLOG = word_to_number("PROLOG")


        if 2 * LOGIC == PROLOG:
            if char_to_digit['L'] != 0 and char_to_digit['P'] != 0:
                print(f"Solution found: LOGIC = {LOGIC}, PROLOG = {PROLOG}")
                print("Character to digit mapping:")
                for char, digit in char_to_digit.items():
                  print(f"{char} = {digit}")
                return char_to_digit


    return print("No solution found.")




def solve_cryptarithmetic(puzzle):


    letters = set(''.join([word for word in puzzle if word.isalpha()]))
    print(f"\nUnique characters: {letters}")


    if len(letters) > 10:
        print("Too many unique letters to solve the puzzle.")
        return None


    for perm in permutations(range(10), len(letters)):
        letter_to_digit = dict(zip(letters, perm))
       
        def word_to_number(word):
            return int(''.join(str(letter_to_digit[char]) for char in word))


        left_side, right_side = puzzle.split("=")
        terms = [term.strip() for term in left_side.split("+")]
        result = right_side.strip()


        if any(letter_to_digit[word[0]] == 0 for word in terms + [result] if len(word) > 1):
            continue


        if sum(word_to_number(term) for term in terms) == word_to_number(result):
            print(f"Solution for {puzzle} is :")
            print("Letter to digit mapping:")
            for letter, digit in letter_to_digit.items():
                print(f"{letter} = {digit}")
            return None


    return print(f"No solution found for '{puzzle}'.")


p1 = "ABCD + EBCB = AFGAG"
p2 = "LOGIC + LOGIC = PROLOG"
p3 = "ONE + ONE + ONE + ONE = TEN"
p4 = "SEND + MORE = MONEY"


print("\nSEND + MORE = MONEY")
send_more_money()
print("\nLOGIC + LOGIC = PROLOG")
logic_prolog()
print("\ngeneral code to solve the above problems")
solve_cryptarithmetic(p1)
solve_cryptarithmetic(p2)
solve_cryptarithmetic(p3)
solve_cryptarithmetic(p4)
