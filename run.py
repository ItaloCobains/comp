import subprocess

def run_make():
    try:
        subprocess.run(['make'], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Ocorreu um erro ao executar o make: {e}")
    else:
        print("Comando make executado com sucesso!")

if __name__ == "__main__":
    run_make()
