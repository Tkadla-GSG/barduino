import React, { Component } from 'react';
import Beverage from './components/Beverage';

class App extends Component {
    render() {
        return (
            <div>
                <Beverage id="beer"/>
                <Beverage id="mimosa"/>
                <Beverage id="other"/>
            </div>
        );
    }
}

export default App;
