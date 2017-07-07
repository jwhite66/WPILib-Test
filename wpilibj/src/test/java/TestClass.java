import org.junit.BeforeClass;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class TestClass {
    @Test
    public void generalTestCase() {
        assertEquals(true, true);
    }

    @Test
    public void jniTest() {
        edu.wpi.first.wpilibj.networktables.NetworkTablesJNI.flush();
        assertEquals(2,2);
    }
}