//
// Authors: Valerio Bertone: valerio.bertone@cern.ch
//          Emanuele R. Nocera: emanuele.nocera@ed.ac.uk
//

#pragma once

// Ceres solver
#include <ceres/ceres.h>
#include <NangaParbat/chisquare.h>

// Standard libs
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <csignal>

namespace Denali
{
  class IterationCallBack : public ceres::IterationCallback
  {
  public:
    IterationCallBack(bool VALIDATION,
                      std::string OutputFolder,
                      int replica,
                      std::vector<double*> const &Parameters,
                      NangaParbat::ChiSquare *chi2t,
                      NangaParbat::ChiSquare *chi2v);

    virtual ceres::CallbackReturnType operator()(const ceres::IterationSummary &);

    int GetBestIteration() { return _BestIteration; };
    double GetBestValidationChi2() { return _Bestchi2v; };
    std::vector<double> GetBestParameters() { return _BestParameters; };

  private:
    const bool _VALIDATION;
    const std::string _OutputFolder;
    const int _replica;
    int _BestIteration;
    double _Bestchi2v;
    std::vector<double> _BestParameters;
    std::vector<double*> _Parameters;
    NangaParbat::ChiSquare *_chi2t;
    NangaParbat::ChiSquare *_chi2v;
  };
} // namespace Denali
