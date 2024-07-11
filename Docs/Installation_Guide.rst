.. _installation_guide:

.. raw:: html

    <style>.highlight {
            background-color: #E7FC9F;
            color: #000000;
            padding: 6px;
            font-size: 12px;
            font-weight: 100;
        }
            .keyword-highlight {
            background-color: #FFFFF0;
            color: #FF3366;
            padding: 6px;
            font-size: 12px;
            font-weight: 100;
        }
    </style>

Installation Guide
==================

.. raw:: html

    <div style="text-align: justify;">
    DDGWizard mainly consists of two parts: the prediction part, used to predict ΔΔG, and the characterization part, which extracts features from the raw ΔΔG dataset to generate a feature set.
    <p></p>
    This section includes the installation guides for both parts.
    <p></p>
    <h4>Installation prerequisites:</h4>
    CentOS 7 or Ubuntu system; GCC version higher than 4.8.5; Conda version higher than 23.0; Git.
    <p></p>
    </div>

.. _`the Prediction Part`:

the Prediction Part
-------------------

.. raw:: html

    <div style="text-align: justify;">
    This installation guide is intended for users who aim to predict ΔΔG.
    <p></p>
    The installation steps are as follows, which will take about 1 hour.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>1. Git clone the DDGWizard repository</h4>
    <p></p>
    </div>

.. code-block::

    $ git clone https://github.com/Mingkai14/DDGWizard.git

.. raw:: html

    <div style="text-align: justify;">
    <h4>2. Config and install conda virtual environment</h4>
    <p></p>
    <p>There is a <span class="keyword-highlight">environment.yml</span> file at the path <span class="keyword-highlight">DDGWizard/src</span>, which is the Conda environment configuration file.</p>
    <p></p>
    <p>Open this file.</p>
    <p></p>
    </div>

.. code-block::

    $ cd DDGWizard/src/
    % vi environment.yml

.. raw:: html

    <div style="text-align: justify;">
    <p>Modify the prefix, which is on the last line. <b>Change the prefix to your local conda envs folder.</b></p>
    <p></p>
    <p>Then use Conda commands to create a Conda virtual environment and install dependencies. This may take some time.</p>
    <p></p>
    </div>

.. code-block::

     $ conda env create -f environment.yml

.. raw:: html

   <div style="text-align: justify;">
   <h4>3. Configure Modeller</h4>
   <p></p>
   The Modeller is software used to generate mutation structures of PDB files.
   <p></p>
   It was already installed when creating Conda environment. But to allow our program to use it, you need to have a license of the Modeller and configure it.
   <p></p>
   You need to enter <a href="https://salilab.org/modeller/registration.html">the official Modeller website</a>, register an account and obtain a license. You can simply follow their instructions to achieve this.
   <p></p>
   Once you obtain the license of the Modeller, you need to input the license into installed Modeller's configuration file. You can find it under the <span class="keyword-highlight">Conda envs folder</span>.
   <p></p>
   Enter your <span class="keyword-highlight">Conda envs folder</span>, and open the Modeller's configuration file:
   <p></p>
   </div>

.. code-block::

     $ vi DDGWizard/lib/modeller-10.4/modlib/modeller/config.py

.. raw:: html

    <div style="text-align: justify;">
    <p>Replace the XXXX to your license. Save and close it.</p>
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>4. Configure DSSP</h4>
    The DSSP is software used to calculate the RSA (relative surface area) and secondary stuctures of PDB files.
    <p></p>
    Due to the version conflict issues, you must do operations below to make DSSP can be used of our program.
    <p></p>
    Enter your <span class="keyword-highlight">Conda envs folder</span>, then enter <span class="keyword-highlight">bin folder</span>, and copy <span class="keyword-highlight">mkdssp</span> (a modified version of dssp) as <span class="keyword-highlight">dssp</span>:
    </div>

.. code-block::

    $ cd DDGWizard/bin/
    $ cp mkdssp dssp

.. raw:: html

    <div style="text-align: justify;">
    <h4>5. Make sure the programs of the DDGWizard have the executable permission</h4>
    The programs of DDGWizard need the executable permission to run.
    <p></p>
    Return to the top folder where you downloaded DDGWizard using <span class="keyword-highlight">git clone</span> (the DDGWizard program folder) and execute the command:
    <p></p>
    </div>

.. code-block::

    $ chmod -R +x .

.. _`the Characterization part`:

the Characterization Part
----------------------------------------

.. raw:: html

    <div style="text-align: justify;">
    This installation guide is intended for users who aim to characterize raw ΔΔG data. It will output complete ΔΔG feature set for analysis or machine learning purposes.
    <p></p>
    The characterization part requires additional prerequisites to meet the needs of calculation for complete feature set. The characterization part uses certain R-based packages and certain cross-platform software, thus requiring dependencies on the R language and the container system.
    <p></p>
    <h4>Additional prerequisites:</h4>
    R; Docker or Singularity (Only one is needed).
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>1. Complete the 1-5 steps of the prediction part</h4>
    <p></p>
    Perform the same operations as steps 1-5 in the prediction part.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>2. Install Bio3D</h4>
    The package <span class="keyword-highlight">Bio3D</span> used to calculate the NMA (normal mode analysis) features.
    <p></p>
    Open your <span class="keyword-highlight">R</span> and use following commands to install package <span class="keyword-highlight">Bio3D</span>:
    <p></p>
    </div>

.. code-block::

    install.packages("bio3d")

.. raw:: html

    <div style="text-align: justify;">
    <h4>3. For container</h4>
    As long as your system has installed and configured the one of <span class="keyword-highlight">Docker</span> or <span class="keyword-highlight">Singularity</span>, the characterization program can run normally.
    <p></p>
    The program will automatically call the container images in the path <span class="keyword-highlight">DDGWizard/src/Prof_Source/</span> and use the software within.
    <p></p>
    <b>One thing to note is that:</b>
    <p></p>
    Please check if the container image files <span class="keyword-highlight">myprof.tar</span> and <span class="keyword-highlight">myprof.sif</span> in the path <span class="keyword-highlight">DDGWizard/src/Prof_Source/</span> are complete. Since they are large files, managed by <a href="https://git-lfs.com/">the Git LFS</a>, sometimes they can not be downloaded completely.
    <p></p>
    If they are not complete, please visit <a href="https://github.com/Mingkai14/DDGWizard/tree/latest6/src/Prof_Source">the DDGWizard GitHub website</a> to manually download them and replace them in the folder <span class="keyword-highlight">DDGWizard/src/Prof_Source/</span>.
    <p></p>
    </div>


