import React, { Component } from 'react';
import Beverage from './components/Beverage';

class App extends Component {
    render() {
        return (
            <div>
                <Beverage id="1" title="On"/>
                <Beverage id="2" title="Off"/>
            </div>
        );
    }
}

export default App;
