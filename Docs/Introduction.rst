.. _introduction:

Introduction
=============

.. raw:: html

   <b>Background:</b>
   <div style="text-align: justify;">
   Thermostability is an important property of proteins and a critical factor for their wide application. Until now, rational/semi-rational design combined with computational methods have become widely used strategies to increase protein thermostability. ΔΔG prediction methods based on machine learning are among these computational methods and have been widely proposed [1]. However, they still suffer from the issue of insufficient prediction performance [2]. The main reasons include that the features used for training models are insufficiently informative [2].
   </div>
   <p></p>
   <b>Characteristics:</b>
   <div style="text-align: justify;">
   To conduct more sufficient feature engineering, we constructed a comprehensive ΔΔG feature set by integrating current ΔΔG feature resources and developed a feature extraction pipeline to extract features from raw ΔΔG data. Furthermore, feature dimensionality reduction was conducted to select the optimal features and develop a ΔΔG prediction model. The model showed notable performance, achieving an R-squared of 0.61 in cross-validation and outperformed other representative ΔΔG prediction methods (ACDC-NN[3], DDGun3D[4], FoldX[5], DynaMut[6], DUET[7], mCSM[8], and SDM[9]) in different comparisons. The developed feature extraction pipeline and ΔΔG prediction model constituted our new ΔΔG prediction system, named DDGWizard.
   </div>
   <p></p>

.. figure:: ./Introduction_res/figure1.png
   :align: center

.. raw:: html

   <div style="width: 42%; margin: auto;"><p style="font-size: 10px;font-weight: 100;white-space: nowrap;">Figure 1. The development and validation processes of DDGWizard.</p></div>

.. raw:: html

   <p></p>
   <b>Purpose:</b>
   <div style="text-align: justify;">
   The application program and source code have been published here, potentially prompting DDGWizard to become a useful resource for aiding rational design of protein thermostability.
   </div>
   <p></p>


