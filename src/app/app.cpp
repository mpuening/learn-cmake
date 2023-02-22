#include <iostream>

#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"

#include "actuator/health.h"
#include "actuator/info.h"
#include "logger/poco.h"

using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::OptionCallback;

// https://raw.githubusercontent.com/ISISComputingGroup/poco/master/Util/samples/SampleApp/src/SampleApp.cpp

class App: public Application {
public:
	App() :
			_runApp(true) {
	}

protected:
	void initialize(Application &self) override {
		loadConfiguration();
		Application::initialize(self);
		LearnCMake::registerPocoLogger(this->logger());
	}

	void reinitialize(Application &self) override {
		Application::reinitialize(self);
	}

	void uninitialize() override {
		Application::uninitialize();
	}

	void defineOptions(OptionSet &options) override {
		Application::defineOptions(options);

		options.addOption(
				Option("version", "v", "Display app version").required(false).repeatable(
						false).callback(
						OptionCallback<App>(this, &App::handleVersion)));

		options.addOption(
				Option("help", "h", "Display help information").required(false).repeatable(
						false).callback(
						OptionCallback<App>(this, &App::handleHelp)));
	}

	void handleVersion(const std::string &name, const std::string &value) {
		_runApp = false;
		LearnCMake::Info().logInfo();
	}

	void handleHelp(const std::string &name, const std::string &value) {
		_runApp = false;
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("A sample application to help learn CMake.");
		helpFormatter.format(std::cout);
		stopOptionsProcessing();
	}

	int main(const ArgVec &args) override {
		if (_runApp) {
			this->logger().information(
					"Status: " + LearnCMake::Health().getStatus());
		}
		return Application::EXIT_OK;
	}

private:
	bool _runApp;
};

POCO_APP_MAIN(App)

