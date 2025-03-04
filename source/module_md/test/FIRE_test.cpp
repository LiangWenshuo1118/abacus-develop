#include "gtest/gtest.h"
#include "setcell.h"
#include "module_md/FIRE.h"
#include "module_esolver/esolver_lj.h"

#define doublethreshold 1e-12

class FIRE_test : public testing::Test
{
protected:
    Verlet *verlet;
    UnitCell_pseudo ucell;

    void SetUp()
    {
        Setcell::setupcell(ucell);
        Setcell::parameters();

        ModuleESolver::ESolver *p_esolver = new ModuleESolver::ESolver_LJ();
        p_esolver->Init(INPUT, ucell);

        verlet = new FIRE(INPUT.mdp, ucell);
        verlet->setup(p_esolver);
    }

    void TearDown()
    {
        delete verlet;
    }
};

TEST_F(FIRE_test, setup)
{
    EXPECT_NEAR(verlet->temperature_, 299.99999999999665, doublethreshold);
    EXPECT_NEAR(verlet->stress(0,0), 6.0100555286436806e-06, doublethreshold);
    EXPECT_NEAR(verlet->stress(0,1), -1.4746713013791574e-06, doublethreshold);
    EXPECT_NEAR(verlet->stress(0,2), 1.5039983732220751e-06, doublethreshold);
    EXPECT_NEAR(verlet->stress(1,0), -1.4746713013791574e-06, doublethreshold);
    EXPECT_NEAR(verlet->stress(1,1), 3.4437172989317909e-06, doublethreshold);
    EXPECT_NEAR(verlet->stress(1,2), -1.251414906590483e-06, doublethreshold);
    EXPECT_NEAR(verlet->stress(2,0), 1.5039983732220751e-06, doublethreshold);
    EXPECT_NEAR(verlet->stress(2,1), -1.251414906590483e-06, doublethreshold);
    EXPECT_NEAR(verlet->stress(2,2), 1.6060561926126463e-06, doublethreshold);
}

TEST_F(FIRE_test, first_half)
{
    verlet->first_half();
    
    EXPECT_NEAR(verlet->pos[0].x, 9.995455294044568, doublethreshold);
    EXPECT_NEAR(verlet->pos[0].y, 0.003264683323249327, doublethreshold);
    EXPECT_NEAR(verlet->pos[0].z, 9.9994784290476932, doublethreshold);
    EXPECT_NEAR(verlet->pos[1].x, 5.2052136746814073, doublethreshold);
    EXPECT_NEAR(verlet->pos[1].y, 5.19405131115556, doublethreshold);
    EXPECT_NEAR(verlet->pos[1].z, 0.0035886062145122004, doublethreshold);
    EXPECT_NEAR(verlet->pos[2].x, 5.0947593079696478, doublethreshold);
    EXPECT_NEAR(verlet->pos[2].y, 0.00048706739346586134, doublethreshold);
    EXPECT_NEAR(verlet->pos[2].z, 4.9979870945593055, doublethreshold);
    EXPECT_NEAR(verlet->pos[3].x, 0.0045717233044145923, doublethreshold);
    EXPECT_NEAR(verlet->pos[3].y, 5.3021969381277305, doublethreshold);
    EXPECT_NEAR(verlet->pos[3].z, 4.9989458701784848, doublethreshold);

    EXPECT_NEAR(verlet->vel[0].x, -0.00010993118004167345, doublethreshold);
    EXPECT_NEAR(verlet->vel[0].y, 7.8968913216100539e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[0].z, -1.2616198016939999e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[1].x, 0.00012611275970351733, doublethreshold);
    EXPECT_NEAR(verlet->vel[1].y, -0.00014389190209072655, doublethreshold);
    EXPECT_NEAR(verlet->vel[1].z, 8.6804233262820007e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[2].x, -0.00012676627812260489, doublethreshold);
    EXPECT_NEAR(verlet->vel[2].y, 1.1781596840062159e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[2].z, -4.8689854212330001e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[3].x, 0.00011058469846166102, doublethreshold);
    EXPECT_NEAR(verlet->vel[3].y, 5.3141392034653857e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[3].z, -2.5498181033639999e-05, doublethreshold);
}

TEST_F(FIRE_test, second_half)
{
    verlet->first_half();
    verlet->second_half();
    
    EXPECT_NEAR(verlet->pos[0].x, 9.995455294044568, doublethreshold);
    EXPECT_NEAR(verlet->pos[0].y, 0.003264683323249327, doublethreshold);
    EXPECT_NEAR(verlet->pos[0].z, 9.9994784290476932, doublethreshold);
    EXPECT_NEAR(verlet->pos[1].x, 5.2052136746814073, doublethreshold);
    EXPECT_NEAR(verlet->pos[1].y, 5.19405131115556, doublethreshold);
    EXPECT_NEAR(verlet->pos[1].z, 0.0035886062145122004, doublethreshold);
    EXPECT_NEAR(verlet->pos[2].x, 5.0947593079696478, doublethreshold);
    EXPECT_NEAR(verlet->pos[2].y, 0.00048706739346586134, doublethreshold);
    EXPECT_NEAR(verlet->pos[2].z, 4.9979870945593055, doublethreshold);
    EXPECT_NEAR(verlet->pos[3].x, 0.0045717233044145923, doublethreshold);
    EXPECT_NEAR(verlet->pos[3].y, 5.3021969381277305, doublethreshold);
    EXPECT_NEAR(verlet->pos[3].z, 4.9989458701784848, doublethreshold);

    EXPECT_NEAR(verlet->vel[0].x, -0.00010978976887416819, doublethreshold);
    EXPECT_NEAR(verlet->vel[0].y, 7.9202349471957007e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[0].z, -1.2616198016939999e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[1].x, 0.00012592893778281191, doublethreshold);
    EXPECT_NEAR(verlet->vel[1].y, -0.00014408187344675441, doublethreshold);
    EXPECT_NEAR(verlet->vel[1].z, 8.6804233262820007e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[2].x, -0.00012686679539500493, doublethreshold);
    EXPECT_NEAR(verlet->vel[2].y, 1.2011267908381344e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[2].z, -4.8689854212330001e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[3].x, 0.00011072762648726122, doublethreshold);
    EXPECT_NEAR(verlet->vel[3].y, 5.2868256066506055e-05, doublethreshold);
    EXPECT_NEAR(verlet->vel[3].z, -2.5498181033639999e-05, doublethreshold);
}