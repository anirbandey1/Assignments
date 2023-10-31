% Name - Anirban Dey
% Roll - 002111001108
%
%
% Question :-
%
% Implement the animal identification game (simple expert system).
% Write a small and simple prolog program to create an efficient rule-based system that attempts to identify 10 different animals based on their characteristics.
%
% Solution :-

% Knowledge base with animals and their characteristics as lists
animal(lion, [carnivore, fur, mammals, 4]).
animal(boar, [omnivore, fur, mammals, 4]).
animal(elephant, [herbivore, rough_skin, mammals, 4]).
animal(kangaroo, [herbivore, fur, mammals, 2]).
animal(whale, [herbivore, smooth_skin, mammals, 0]).
animal(hawk, [carnivore, feathers, birds, 2]).
animal(tiger, [carnivore, fur, mammals, 4]).
animal(butterfly, [herbivore, scales, insects, 6]).
animal(spider, [carnivore, smooth_skin, insects, 8]).
animal(parrot, [herbivore, feathers, birds, 2]).

% Predicate to ask the user for a feature value
ask_feature_value(Feature, Options, Value) :-
    write('Enter a value for '), write(Feature), write(Options), write(': '),
    read(Value).

ask_feature_value('no_of_legs', '', NoOfLegs) :-
    write('Enter the number of legs: '),
    read(NoOfLegs).

% Predicate to check if an animal has a specified feature
animal_has_feature(Animal, Feature) :-
    animal(Animal, Features),
    member(Feature, Features).

% Predicate to filter valid animals based on feature
filter_valid_animals([], _, []).
filter_valid_animals([Animal|Rest], Feature, ValidAnimals) :-
    (animal_has_feature(Animal, Feature) ->
        ValidAnimals = [Animal|NewValidAnimals]
    ;
        ValidAnimals = NewValidAnimals
    ),
    filter_valid_animals(Rest, Feature, NewValidAnimals).

% Main predicate to interact with the user and update the list of valid animals
main :-
    % Initialize the list of valid animals with all animals
    findall(Animal, animal(Animal, _), AllAnimals),
    writeln('Initial list of valid animals: '),
    writeln(AllAnimals), nl,
    
    % Ask for feature values and update the list
    ask_feature_value('diet', ' [carnivore/herbivore]', Diet),
    filter_valid_animals(AllAnimals, Diet, UpdatedAnimals1),
    writeln('Current list of valid animals: '),
    writeln(UpdatedAnimals1), nl,

    ask_feature_value('skin_type', ' [fur/rough_skin/smooth_skin/feathers/scales]', SkinType),
    filter_valid_animals(UpdatedAnimals1, SkinType, UpdatedAnimals2),
    writeln('Current list of valid animals: '),
    writeln(UpdatedAnimals2), nl,

    ask_feature_value('animal_class', ' [mammals/birds/insects]', AnimalClass), % Ask for animal class
    filter_valid_animals(UpdatedAnimals2, AnimalClass, UpdatedAnimals3),
    writeln('Current list of valid animals: '),
    writeln(UpdatedAnimals3), nl,

    ask_feature_value('no_of_legs', '', NoOfLegs), % Ask for number of legs
    filter_valid_animals(UpdatedAnimals3, NoOfLegs, FinalValidAnimals),

    % Display the final list of valid animals
    writeln('Final list of valid animals: '),
    writeln(FinalValidAnimals).

