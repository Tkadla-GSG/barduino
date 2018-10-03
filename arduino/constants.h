
// ESP8266 to Arduino commands
#define COMMAND_SEPARATOR			";"
#define COMMAND_TEMPLATE			"%s|%s" + COMMAND_SEPARATOR	// command|id;

#define COMMAND_BREW				"brew"
#define COMMAND_MOTOR_OFF			"motor_off"
#define COMMAND_MOTOR_ON_LOAD		"motor_on_load"
#define COMMAND_MOTOR_ON_UNLOAD		"motor_on_unload"

// Arduino to ESP8266 responses
#define STATUS_TEMPLATE				"%b|%f;"	// brewing|qeueLength;