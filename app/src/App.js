import React, { Component } from 'react';
import styled from 'styled-components';
import Beverage from './components/Beverage';
import Controls from './components/Controls';

const AppWrapper = styled.div`
    min-height: 100vh;
    position: relative;
    overflow: hidden;
    padding-bottom: 48px;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
`;

class App extends Component {
    render() {
        return (
            <AppWrapper>
                <Beverage id="1" title="white russian"/>
                <Beverage id="2" title="black russian"/>
                <Beverage id="3" title="houba"/>
                <Beverage id="4" title="kubicko"/>
                <Beverage id="5" title="sydney"/>
                <Beverage id="6" title="rum + rum"/>
                <Controls />
            </AppWrapper>
        );
    }
}

export default App;
