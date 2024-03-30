import random
import os
import subprocess

def generate_input():
    current_dir = os.path.dirname(os.path.abspath(__file__))
    current_dir = os.path.join(current_dir, f"test")
    if not os.path.exists(current_dir):
        os.makedirs(current_dir)
    for i in range(1, 4):

        file_name = os.path.join(current_dir, f"in{i}.txt")

        with open(file_name, 'w') as f:
            t = random.randint(1, 100)
            for _ in range(t):
                a = random.randint(1, 100)
                b = random.randint(1, 100)
                k = random.randint(1, 100)
                f.write(f"{a} {b} {k}\n")
                    

def std_output(input_file, output_file):
    current_dir = os.path.dirname(os.path.abspath(__file__))
    std_exe_path = os.path.join(current_dir, r"output\std.exe")

    with open(input_file, 'r') as input_fh, open(output_file, 'w') as output_fh:
        subprocess.run([std_exe_path], stdin=input_fh, stdout=output_fh)

def generate_output():
    current_dir = os.path.dirname(os.path.abspath(__file__))
    current_dir = os.path.join(current_dir, "test")

    for i in range(1, 4):
        input_file = os.path.join(current_dir, f"in{i}.txt")
        output_file = os.path.join(current_dir, f"out{i}.txt")
        std_output(input_file, output_file)

if __name__ == "__main__":
    generate_input()
    generate_output()

