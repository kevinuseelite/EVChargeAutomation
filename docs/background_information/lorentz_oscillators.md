# Lorentz Oscillators

The optical interactions between light and matter at the nanometer scale are important phenomena for a variety of research fields, and a rigorous understanding of these interactions requires the use of QED theory. However, nanometer-scale structures are often too complex to be solved rigorously using only QED; in these cases, a classical approach that invokes the results of QED in a phenomenological way can be applied. PyCharge uses the Lorentz oscillator (LO) model, which is an approximation from quantum theory that can be derived (e.g., from the time-dependent Schrödinger equation or a quantum master equation) to simulate the interaction of a bound charge (e.g., an electron) with light.

In the classical model, an oscillating dipole produces EM radiation which dissipates energy and modifies the self-consistent dipole moment. The recoil force, $\mathbf{F}_\mathrm{r}$, acting on the accelerating point charges in the dipole is called the radiation reaction or radiation damping force. The equation of motion for an undriven LO (e.g., in a vacuum) that includes the radiation reaction force is given by

$$
\label{eq:underiven_EOM}
m\mathbf{\ddot r_{\rm dip}}(t) + \omega_0^2 m \mathbf{r_\mathrm{dip}}(t) = \mathbf{F}_\mathrm{r}(t),
$$

where $\mathbf{r}_{\rm dip}$ is the displacement from the LO's negative charge to positive charge and $\mathbf{\ddot r_{\rm dip}}$ is its second derivative with respect to time, $m$ is the effective mass of the LO (further discussed below), and $\omega_0$ is the natural angular frequency of the LO.

The radiation reaction force, $\mathbf{F}_\mathrm{r}$, acting on the accelerating point charges in the dipole is described by the Abraham-Lorentz formula for non-relativistic velocities:

$$
\mathbf{F}_\mathrm{r}(t)=\frac{q^2}{6\pi\epsilon_oc^3}\mathbf{\dddot r_\mathrm{dip}}(t),
$$

where $\mathbf{\dddot r_\mathrm{dip}}$ is the third derivative of the displacement between the two charges. We can perform the approximation ${\mathbf{\dddot r}_\mathrm{dip}\approx -\omega_0^2\mathbf{\dot r}_\mathrm{dip}}$ in the above equation if the damping on the point charges introduced by the radiation reaction force is negligible (i.e., $|\mathbf{F}_\mathrm{r}| \ll \omega_0^2 m |\mathbf{r}_\mathrm{dip}|$), such that the following condition is satisfied:

\begin{equation}\label{eq:dipole_condition}
\frac{q^2 \omega_0}{m} \ll 6\pi \epsilon_0 c^3.
\end{equation}

In an inhomogeneous environment, an oscillating electric dipole will experience the external electric field $\mathbf{E}_\mathrm{d}$ as a driving force, which is the component of the total electric field in the polarization direction at the dipole's origin (center of mass) position $\mathbf{R}$ generated by the other sources in the system and its own scattered field. If the above condition is satisfied, the equation of motion for a driven LO is

\begin{equation}\label{eq:LO_equation}
\mathbf{\ddot d}(t) +\gamma_{0} \mathbf{\dot d}(t) +\omega_{0}^{2} {\bf d}(t)= \frac{q^2}{m} \mathbf{E}_\mathrm{d}(\mathbf{R}, t),
\end{equation}

where ${\bf d}=q{\bf r_{\rm dip}}$ is the dipole moment, $\mathbf{\dot d}$ and $\mathbf{\ddot d}$ are the first and second derivatives of $\mathbf{d}$, and $\gamma_0$ is the free-space _energy decay rate_ given by

\begin{equation}
\gamma_0 = \frac{q^2\omega_0^2}{6\pi\epsilon_0c^3m}.
\end{equation}

This equation of motion for an LO corresponds to a Lorentzian atom model with transition frequency $\omega_0$ and linewidth $\gamma_0$ (where $\gamma_0 \ll \omega_0$), and is limited to non-relativistic velocities as it does not account for relativistic mass.

The effective mass $m$ (also called the reduced mass) of the dipole is given by

\begin{equation}
\label{eq:eff_mass}
m=\frac{m_1 m_2}{m_1+m_2},
\end{equation}

where $m_1$ and $m_2$ are the masses of the two point charges in the dipole. These charges oscillate around the center of mass position $\mathbf{R}$, defined by

\begin{equation}
\mathbf{R} = \frac{m_1\mathbf{r}_1+m_2\mathbf{r}_2}{m_1+m_2},
\end{equation}

where $\mathbf{r}_1$ and $\mathbf{r}_2$ are the positions of the two point charges. The point charge positions can therefore be defined in terms of the displacement between the two charges $\mathbf{r}_\mathrm{dip}$:

\begin{equation}
\label{eq:r_1}
\mathbf{r}_1 = \mathbf{R} + \frac{m_2}{m_1+m_2}\mathbf{r}_\mathrm{dip}
\end{equation}

and

\begin{equation}
\label{eq:r_2}
\mathbf{r}_2 = \mathbf{R} - \frac{m_1}{m_1+m_2}\mathbf{r}_\mathrm{dip}.
\end{equation}

It is also useful to discuss how the decay dynamics of LOs are related to those of a quantum TLS, in certain limits.
Specifically,
in the limit of weak excitation (linear response), we can connect the
quantum mechanical equations of motion for a TLS to the
classical equations of motion by replacing $q^2/m$ with $q^2f/m$, where
$f$ is the oscillator strength, defined by

\begin{equation}
\label{eq:f}
f = \frac{2m \omega_0 d_0^2}{\hbar q^2},
\end{equation}

where $d_0=|\mathbf{d}(t=0)|$. We thus recover the usual expression for the SE rate $\gamma_{0,\mathrm{TLS}}$ from an excited TLS,

\begin{equation}
\label{eq:SE0}
\gamma_{0,\mathrm{TLS}} = \frac{\omega_0^3 d_0^2}{3\pi\epsilon_0 \hbar c^3}.
\end{equation}

An alternative argument to relate the dipole moment with the radiative decay rate is to connect the total mean energy of the LO to the ground state energy of a quantized harmonic oscillator, so that

\begin{equation}
\frac{m\omega_0^2 d_0^2}{q^2} = \frac{\hbar\omega_0}{2},
\end{equation}

yielding $q^2/m = 2\omega_0d_0^2/\hbar$, as expected. As well, the decay rate can be derived using a Fermi's golden rule approach from the interaction Hamiltonian
$H_\mathrm{int} = -{\bf d} \cdot \hat{\bf E}$, which leads to the following 
rate equations for the populations 
of an isolated TLS in a vacuum:

\begin{equation}
\label{eq:n_e}
\dot n_\mathrm{e}(t) = -\gamma_0 n_\mathrm{e}(t)
\end{equation}

and

\begin{equation}
\label{eq:n_g}
\dot n_\mathrm{g}(t) = \gamma_0 n_\mathrm{e}(t),
\end{equation}

where $n_g$ and $n_e$ are the populations of the ground and excited states ($n_g+n_e=1$), respectively, and we neglect all other processes. In this picture,
$\gamma_0$ is also identical to the well known Einstein A coefficient. Therefore, the energy decay rate is equivalent to the population decay rate.
We stress again that we can only make the connection between LO dynamics and populations of
TLS states in a regime of weak excitation.

The total energy $\mathcal{E}$ of a dipole, which is the sum of its kinetic and potential energies, is calculated by PyCharge using

\begin{equation}
\label{eq:dipoleE}
\mathcal{E}(t) = \frac{m \omega_0^2}{2q^2} d^2(t) + \frac{m}{2q^2} \dot d^2(t),
\end{equation}

where $\dot d=|\mathbf{\dot d}|$. Since the total energy of a dipole ${\cal E}$ is proportional to $n_e$, the population of the excited state using the normalized total energy can be determined by PyCharge from

\begin{equation}
\label{eq:ne_energy}
n_e(t)=\frac{\mathcal{E}(t)}{\max (\mathcal{E})}.
\end{equation}

[^1]: L. Novotny and B. Hecht, _Principles of Nano-Optics_, Chapter 8
[^2]: P. Milonni and J. Eberly, _Lasers Physics_, Chapter 3
[^3]: D. Griffiths, _Introduction ot Electrodynamics_, Chapter 11