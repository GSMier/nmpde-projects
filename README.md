
<table>
  <tr>
    <td width="40%" align="center" valign="middle">
      <img
        src="https://i.imgur.com/IVcWt3w.png"
        width="300"
        alt="er cubozzo"
      />
    </td>
    <td width="60%" valign="middle">
      <h1>NMPDE Project 10</h1>
      <h2>Inverse Problem for the Heat Equation [A]</h2>
      <p>
        Neural network approximation and inverse identification
        of thermal diffusivity.
      </p>
    </td>
  </tr>
</table>

<p align="center">
  <sub>
Illustrative heat-equation graphic of a cube heated from below. This picture is not from our project.
  </sub>
</p>


### Group members:
- Uriel Enrico Fumagalli - 11036212
- Nicolò Grattagliano - 10909733
- Gian Sebastian Mier Bello - 11225652
- Marco Gabriele Sogni - 10840679

This project investigates the **inverse identification of thermal diffusivity** from temperature measurements. The forward model is the heat equation formula applied on the unit cube, initially at zero temperature, with a prescribed temperature on the bottom face. Here are the formulas governing the body simulation

$$
\begin{aligned}
\partial_t u - \mu\,\Delta u &= 0 && \text{in } \Omega\times(0,T],\\
u &= u_D && \text{on } \Gamma_D,\\
\mu\nabla u\cdot n &= 0 && \text{on } \Gamma_N,\\
u(\cdot,0) &= 0 && \text{in } \Omega,
\end{aligned}
\qquad \Omega=(0,1)^3.
$$

The aim is to train a neural network that approximates the parametric solution map $(x,t,\mu)\mapsto u(x,t;\mu)$, then recover an unknown $\mu^*$ from sparse, noisy sensor measurements by solving

$$
\widehat{\mu}^* = \arg\min_{\mu\in[\mu_{\min},\mu_{\max}]}
\sum_{i=1}^{N_s}\sum_{j=1}^{N_t}
\left|d_{ij}-u_{NN}(x_i,t_j;\mu)\right|^2.
$$

## Planned work

1. **FEM simulation and data generation** - from an accurate finite element simulation of the model we generate accurate solutions to train our neural network and provide correct references.
2. **Neural network surrogate** - we train a JAX neural network that approximates the FEM parametric forward map; we will motivate the architecture, training data, and loss function.
3. **Inverse identification** - we estimate $\mu^*$ from the sensor measurements and assess accuracy and robustness as we increase the noise levels.

## Build and run

```bash
git clone https://github.com/GSMier/nmpde-projects.git
cd nmpde-projects

apptainer shell ~/amsc_mk_2025.sif
source /u/sw/etc/bash.bashrc
module load gcc-glibc dealii

mkdir -p build
cd build
cmake ..
make

./proj-10
```