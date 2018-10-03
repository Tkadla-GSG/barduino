import React, { Component } from 'react';
import Beverage from './components/Beverage';
import MotorControl from './components/MotorControl';

class App extends Component {
    render() {
        return (
            <div>
                <MotorControl id="1" />
            </div>
        );
    }
}

export default App;
