import React, { Component } from 'react';
import Beverage from './components/Beverage';

class App extends Component {
    render() {
        return (
            <div>
                <Beverage id="1"/>
                <Beverage id="2"/>
                <Beverage id="3"/>
            </div>
        );
    }
}

export default App;
