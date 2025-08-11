#include "platform.h"
// On Android we rely on system haptics via Java if needed; here it's a no-op to be safe.
void platform_vibrate(int){ /* no-op; Android Java layer can be extended to call Vibrator */ }
