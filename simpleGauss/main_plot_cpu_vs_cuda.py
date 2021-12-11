import matplotlib.pyplot as plt
import subprocess
import statistics as stats
import re

ns = [i for i in range(10, 100, 5)]
number_tests = 5

single_core_program_path = './cmake-build-debug/simpleGauss/simpleGauss_simple_gauss_measure_cpu'
cuda_program_path = './cmake-build-debug/simpleGauss/simpleGauss_simple_gauss_measure_cuda'

single_core_ts = []
for n in ns:
    t_lst = []
    for i in range(number_tests):
        process = subprocess.Popen([single_core_program_path, f'{n}'], stdout=subprocess.PIPE)
        stdout = process.communicate()[0].strip().decode('utf-8')
        str_num = re.search(r'(\d+)', stdout).group(0)
        t_lst += [int(str_num)]
    single_core_ts += [stats.mean(t_lst)]

cuda_core_ts = []
for n in ns:
    t_lst = []
    for i in range(number_tests):
        process = subprocess.Popen([cuda_program_path, f'{n}'], stdout=subprocess.PIPE)
        stdout = process.communicate()[0].strip().decode('utf-8')
        str_num = re.search(r'(\d+)', stdout).group(0)
        t_lst += [int(str_num)]
    cuda_core_ts += [stats.mean(t_lst)]


plt.plot(ns, single_core_ts, color='red', label='Обыкновенная однопоточная CPU реализация')
plt.plot(ns, cuda_core_ts, color='blue', label='Реализация на CUDA')

plt.xlabel("Размерность СЛАУ")
plt.ylabel("Время в микросекундах")
plt.legend()
plt.savefig('plot_cpu_vs_cuda.png')