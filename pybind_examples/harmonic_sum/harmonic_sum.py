import time
import sys
sys.path.append("./build")
import c_harmonic


def harmonic_sum(power:int, harmonic_sum: float=1.0)->float:
    for i in range(1,pow(10,power)+1):
        harmonic_sum += 1/i
    return harmonic_sum

def time_calculator(custom_function, config: dict)->None:
    begin_time = time.time()
    harmonic_sum = custom_function(config["power"],config["harmonic_sum"])
    end_time = time.time()
    print("Time Process  " + str(round(end_time - begin_time, 3)) + "s")
    print(f"Harmonic sum {harmonic_sum} for n equals to {config['power']}\n")

if __name__=="__main__":
    config = {"power":9,
        "harmonic_sum":1.0}
    print('Python')
    time_calculator(harmonic_sum,config)

    print('Python powered by C++')
    time_calculator(c_harmonic.c_harmonicsum,config)


