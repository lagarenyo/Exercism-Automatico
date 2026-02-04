
EXPECTED_BAKE_TIME = 40
PREPARATION_TIME = 2

def bake_time_remaining(elapsed_bake_time):
    """ Exercism guidos-gorgeous-lasagna in python """
    return EXPECTED_BAKE_TIME - elapsed_bake_time 

def preparation_time_in_minutes(number_of_layers):
    """ Exercism guidos-gorgeous-lasagna in python """
    return number_of_layers * PREPARATION_TIME
        
def elapsed_time_in_minutes( number_of_layers, elapsed_bake_time ):
    """ Exercism guidos-gorgeous-lasagna in python """
    return elapsed_bake_time + number_of_layers * PREPARATION_TIME


