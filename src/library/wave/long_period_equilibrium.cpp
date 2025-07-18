// Copyright (c) 2025 CNES
//
// All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.
#include "fes/wave/long_period_equilibrium.hpp"

namespace fes {
namespace wave {

// Table below = Doodson coefficients
// tau s   h   p   N'  p1  coef  => Doodson = several combination for
//    waves/secondary waves = variation for N' factor in comparison with
//    Darwin
// T   s   h   p   p1      coef  => Darwin = only combination for each
//    waves, secondary waves are not explicitly described
// clang-format off
LongPeriodEquilibrium::LongPeriodEquilibrium()
    : order2_((Eigen::Matrix<double, 106, 6>() <<   //
               /* 0,*/ 0,  0,  0,  1,  0,  0.02793, //   0 - M0
               /* 0,*/ 0,  0,  0,  2,  0, -0.00027, //   1 - M0
               /* 0,*/ 0,  0,  2,  1,  0,  0.00004, //   2
               /* 0,*/ 0,  1,  0, -1, -1, -0.00004, //   3 - Sa1
               /* 0,*/ 0,  1,  0,  0, -1, -0.00492, //   4 - Sa1
               /* 0,*/ 0,  1,  0,  0,  1,  0.00026, //   5
               /* 0,*/ 0,  1,  0,  1, -1,  0.00005, //   6 - Sa1
               /* 0,*/ 0,  2, -2, -1,  0,  0.00002, //   7
               /* 0,*/ 0,  2, -2,  0,  0, -0.00031, //   8
               /* 0,*/ 0,  2,  0,  0,  0, -0.03095, //   9 - Ssa
               /* 0,*/ 0,  2,  0,  0, -2, -0.00008, //  10
               /* 0,*/ 0,  2,  0,  1,  0,  0.00077, //  11 - Ssa
               /* 0,*/ 0,  2,  0,  2,  0,  0.00017, //  12 - Ssa
               /* 0,*/ 0,  3,  0,  0, -1, -0.00181, //  13 - Sta
               /* 0,*/ 0,  3,  0,  1, -1,  0.00003, //  14 - Sta
               /* 0,*/ 0,  4,  0,  0, -2, -0.00007, //  15
               /* 0,*/ 1, -3,  1, -1,  1,  0.00002, //  16
               /* 0,*/ 1, -3,  1,  0,  1, -0.00029, //  17
               /* 0,*/ 1, -3,  1,  1,  1,  0.00002, //  18
               /* 0,*/ 1, -2, -1, -2,  0,  0.00003, //  19
               /* 0,*/ 1, -2, -1, -1,  0,  0.00007, //  20
               /* 0,*/ 1, -2,  1, -1,  0,  0.00048, //  21
               /* 0,*/ 1, -2,  1,  0,  0, -0.00673, //  22
               /* 0,*/ 1, -2,  1,  1,  0,  0.00043, //  23
               /* 0,*/ 1, -1, -1, -1,  1,  0.00002, //  24
               /* 0,*/ 1, -1, -1,  0,  1, -0.00021, //  25
               /* 0,*/ 1, -1, -1,  1,  1,  0.00000, //  26
               /* 0,*/ 1, -1,  0,  0,  0,  0.00020, //  27
               /* 0,*/ 1, -1,  1,  0, -1,  0.00005, //  28
               /* 0,*/ 1,  0, -1, -2,  0, -0.00003, //  29 - Mm
               /* 0,*/ 1,  0, -1, -1,  0,  0.00231, //  30 - Mm
               /* 0,*/ 1,  0, -1,  0,  0, -0.03518, //  31 - Mm
               /* 0,*/ 1,  0, -1,  1,  0,  0.00228, //  32 - Mm
               /* 0,*/ 1,  0,  1,  0,  0,  0.00189, //  33 - Mm1
               /* 0,*/ 1,  0,  1,  1,  0,  0.00077, //  34 - Mm1
               /* 0,*/ 1,  0,  1,  2,  0,  0.00021, //  35 - Mm1
               /* 0,*/ 1,  1, -1,  0, -1,  0.00018, //  36
               /* 0,*/ 1,  2, -1,  0,  0,  0.00049, //  37
               /* 0,*/ 1,  2, -1,  1,  0,  0.00024, //  38
               /* 0,*/ 1,  2, -1,  2,  0,  0.00004, //  39
               /* 0,*/ 1,  3, -1,  0, -1,  0.00003, //  40
               /* 0,*/ 2, -4,  2,  0,  0, -0.00011, //  41
               /* 0,*/ 2, -3,  0,  0,  1, -0.00038, //  42
               /* 0,*/ 2, -3,  0,  1,  1,  0.00002, //  43
               /* 0,*/ 2, -2,  0, -1,  0, -0.00042, //  44 - A5
               /* 0,*/ 2, -2,  0,  0,  0, -0.00582, //  45 - A5
               /* 0,*/ 2, -2,  0,  1,  0,  0.00037, //  46 - A5
               /* 0,*/ 2, -2,  2,  0,  0,  0.00004, //  47
               /* 0,*/ 2, -1, -2,  0,  1, -0.00004, //  48
               /* 0,*/ 2, -1, -1,  0,  0,  0.00003, //  49
               /* 0,*/ 2, -1,  0,  0, -1,  0.00007, //  50
               /* 0,*/ 2, -1,  0,  0,  1, -0.00020, //  51
               /* 0,*/ 2, -1,  0,  1,  1, -0.00004, //  52
               /* 0,*/ 2,  0, -2, -1,  0,  0.00015, //  53 - Mf1
               /* 0,*/ 2,  0, -2,  0,  0, -0.00288, //  54 - Mf1
               /* 0,*/ 2,  0, -2,  1,  0,  0.00019, //  55 - Mf1
               /* 0,*/ 2,  0,  0,  0,  0, -0.06662, //  56 - Mf
               /* 0,*/ 2,  0,  0,  1,  0, -0.02762, //  57 - Mf
               /* 0,*/ 2,  0,  0,  2,  0, -0.00258, //  58 - Mf
               /* 0,*/ 2,  0,  0,  3,  0,  0.00007, //  59 - Mf
               /* 0,*/ 2,  1, -2,  0, -1,  0.00003, //  60
               /* 0,*/ 2,  1,  0,  0, -1,  0.00023, //  61
               /* 0,*/ 2,  1,  0,  1, -1,  0.00006, //  62
               /* 0,*/ 2,  2, -2,  0,  0,  0.00020, //  63
               /* 0,*/ 2,  2, -2,  1,  0,  0.00008, //  64
               /* 0,*/ 2,  2,  0,  2,  0,  0.00003, //  65
               /* 0,*/ 3, -5,  1,  0,  1, -0.00002, //  66
               /* 0,*/ 3, -4,  1,  0,  0, -0.00017, //  67
               /* 0,*/ 3, -3, -1,  0,  1, -0.00007, //  68
               /* 0,*/ 3, -3,  1,  0,  1, -0.00012, //  69
               /* 0,*/ 3, -3,  1,  1,  1, -0.00004, //  70
               /* 0,*/ 3, -2, -1, -1,  0, -0.00010, //  71
               /* 0,*/ 3, -2, -1,  0,  0, -0.00091, //  72
               /* 0,*/ 3, -2, -1,  1,  0,  0.00006, //  73
               /* 0,*/ 3, -2,  1,  0,  0, -0.00242, //  74
               /* 0,*/ 3, -2,  1,  1,  0, -0.00100, //  75
               /* 0,*/ 3, -2,  1,  2,  0, -0.00009, //  76
               /* 0,*/ 3, -1, -1,  0,  1, -0.00013, //  77
               /* 0,*/ 3, -1, -1,  1,  1, -0.00004, //  78
               /* 0,*/ 3, -1,  0,  0,  0,  0.00006, //  79
               /* 0,*/ 3, -1,  0,  1,  0,  0.00003, //  80
               /* 0,*/ 3, -1,  1,  0, -1,  0.00003, //  81
               /* 0,*/ 3,  0, -3,  0,  0, -0.00023, //  82
               /* 0,*/ 3,  0, -3,  1, -1,  0.00004, //  83
               /* 0,*/ 3,  0, -3,  1,  1,  0.00004, //  84
               /* 0,*/ 3,  0, -1,  0,  0, -0.01275, //  85 - Mtm
               /* 0,*/ 3,  0, -1,  1,  0, -0.00528, //  86 - Mtm
               /* 0,*/ 3,  0, -1,  2,  0, -0.00051, //  87 - Mtm
               /* 0,*/ 3,  0,  1,  2,  0,  0.00005, //  88
               /* 0,*/ 3,  0,  1,  3,  0,  0.00002, //  89
               /* 0,*/ 3,  1, -1,  0, -1,  0.00011, //  90
               /* 0,*/ 3,  1, -1,  1, -1,  0.00004, //  91
               /* 0,*/ 4, -4,  0,  0,  0, -0.00008, //  92
               /* 0,*/ 4, -4,  2,  0,  0, -0.00006, //  93
               /* 0,*/ 4, -4,  2,  1,  0, -0.00002, //  94
               /* 0,*/ 4, -3,  0,  0,  1, -0.00014, //  95
               /* 0,*/ 4, -3,  0,  1,  1, -0.00006, //  96
               /* 0,*/ 4, -2, -2,  0,  0, -0.00011, //  97
               /* 0,*/ 4, -2,  0,  0,  0, -0.00205, //  98 - Msqm
               /* 0,*/ 4, -2,  0,  1,  0, -0.00085, //  99 - Msqm
               /* 0,*/ 4, -2,  0,  2,  0, -0.00008, // 100 - Msqm
               /* 0,*/ 4, -1, -2,  0,  1, -0.00003, // 101
               /* 0,*/ 4, -1,  0,  0, -1,  0.00003, // 102
               /* 0,*/ 4,  0, -2,  0,  0, -0.00169, // 103
               /* 0,*/ 4,  0, -2,  1,  0, -0.00070, // 104
               /* 0,*/ 4,  0, -2,  2,  0, -0.00006  // 105
               ).finished()),
     order3_((Eigen::Matrix<double, 17, 6>() << //
               /* 0,*/ 0,  0,  1,  0,  0, -0.00021,  // 0
               /* 0,*/ 0,  2, -1,  0,  0, -0.00004,  // 1
               /* 0,*/ 1, -2,  0,  0,  0,  0.00004,  // 2
               /* 0,*/ 1,  0,  0, -1,  0,  0.00019,  // 3 - Mm2
               /* 0,*/ 1,  0,  0,  0,  0, -0.00375,  // 4 - Mm2
               /* 0,*/ 1,  0,  0,  1,  0, -0.00059,  // 5 - Mm2
               /* 0,*/ 1,  0,  0,  2,  0,  0.00005,  // 6 - Mm2
               /* 0,*/ 2, -2,  1,  0,  0, -0.00012,  // 7
               /* 0,*/ 2,  0, -1,  0,  0, -0.00061,  // 8 - Mf2
               /* 0,*/ 2,  0, -1,  1,  0, -0.00010,  // 9 - Mf2
               /* 0,*/ 3, -2,  0,  0,  0, -0.00010,  // 10
               /* 0,*/ 3,  0, -2,  0,  0, -0.00007,  // 11
               /* 0,*/ 3,  0,  0,  0,  0, -0.00030,  // 12
               /* 0,*/ 3,  0,  0,  1,  0, -0.00019,  // 13
               /* 0,*/ 3,  0,  0,  2,  0, -0.00004,  // 14
               /* 0,*/ 4,  0, -1,  0,  0, -0.00008,  // 15
               /* 0,*/ 4,  0, -1,  1,  0, -0.00005   // 16
               ).finished()) {}
// clang-format on

auto LongPeriodEquilibrium::disable_dynamic_wave(const Table& table) -> void {
  // Indexes are the same as those defined starting from l.389
  if (table[kMm]->dynamic()) {
    order2_.row(29).fill(0);
    order2_.row(30).fill(0);
    order2_.row(31).fill(0);
    order2_.row(32).fill(0);
  }
  if (table[kMf]->dynamic()) {
    order2_.row(56).fill(0);
    order2_.row(57).fill(0);
    order2_.row(58).fill(0);
    order2_.row(59).fill(0);
  }
  if (table[kMtm]->dynamic()) {
    order2_.row(85).fill(0);
    order2_.row(86).fill(0);
    order2_.row(87).fill(0);
  }
  if (table[kMsqm]->dynamic()) {
    order2_.row(98).fill(0);
    order2_.row(99).fill(0);
    order2_.row(100).fill(0);
  }
  if (table[kSsa]->dynamic()) {
    order2_.row(9).fill(0);
    order2_.row(11).fill(0);
    order2_.row(12).fill(0);
  }
  if (table[kSa1]->dynamic()) {
    order2_.row(4).fill(0);
  }
  if (table[kSta]->dynamic()) {
    order2_.row(13).fill(0);
  }
  if (table[kMm1]->dynamic()) {
    order2_.row(33).fill(0);
    order2_.row(34).fill(0);
    order2_.row(35).fill(0);
  }
  if (table[kMf1]->dynamic()) {
    order2_.row(53).fill(0);
    order2_.row(54).fill(0);
    order2_.row(55).fill(0);
  }
  if (table[kA5]->dynamic()) {
    order2_.row(44).fill(0);
    order2_.row(45).fill(0);
    order2_.row(46).fill(0);
  }
  if (table[kMm2]->dynamic()) {
    order3_.row(3).fill(0);
    order3_.row(4).fill(0);
    order3_.row(5).fill(0);
    order3_.row(6).fill(0);
  }
  if (table[kMf2]->dynamic()) {
    order3_.row(8).fill(0);
    order3_.row(9).fill(0);
  }
}

auto LongPeriodEquilibrium::lpe_minus_n_waves(const angle::Astronomic& angles,
                                              const double lat) -> double {
  // Vector containing the required nodal corrections.
  Eigen::Matrix<double, 5, 1> shpn =
      (Eigen::Matrix<double, 5, 1>() << angles.s(), angles.h(), angles.p(),
       detail::math::two_pi<double>() - angles.n(), angles.p1())
          .finished();

  // Tidal potential V20
  auto h20 = 0.0;
  for (auto ix = 0L; ix < order2_.rows(); ++ix) {
    h20 += std::cos(order2_.row(ix).head(5).dot(shpn)) * order2_(ix, 5);
  }

  // Tidal potential V30
  auto h30 = 0.0;
  for (auto ix = 0L; ix < order3_.rows(); ++ix) {
    h30 += std::sin(order3_.row(ix).head(5).dot(shpn)) * order3_(ix, 5);
  }

  // FES14C: mass conservation for long period equilibrium
  // Subtraction of the mean of c20 and c30 on ocean, for mass conservation
  constexpr auto factor_20 = (1.0 - 0.609 /* H2 */ + 0.302 /* K2 */);
  constexpr auto factor_30 = (1.0 - 0.291 /* H3 */ + 0.093 /* K3 */);
  constexpr auto mean_c20 = -0.014432247 / factor_20;
  // Note: Using factor_20 instead of factor_30 for mean_c30 calculation due
  // to a bug in the original calculation.
  constexpr auto mean_c30 = 0.012469818 / factor_20;

  auto sy = detail::math::sind(lat);
  auto sy2 = detail::math::pow<2>(sy);
  auto c20 =
      std::sqrt(5.0 / (4.0 * detail::math::pi<double>())) * (1.5 * sy2 - 0.5) +
      mean_c20;
  auto c30 = std::sqrt(7.0 / (4.0 * detail::math::pi<double>())) *
                 (2.5 * sy2 - 1.5) * sy -
             mean_c30;

  // m -> cm
  return (factor_20 * c20 * h20 + factor_30 * c30 * h30) * 100;
}

}  // namespace wave
}  // namespace fes
