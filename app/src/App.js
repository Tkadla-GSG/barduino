import React, { Component } from 'react';
import styled from 'styled-components';
import { connect } from 'react-redux'
import Beverage from './components/Beverage';
import Loader from './components/Loader';
import Controls, { HANDLE_HEIGHT } from './components/Controls';
import WhiteRussian from './assets/white-russian.jpg';
import { isBrewing } from './selectors/status';

const GAP = '32px';
const AppWrapper = styled.div`
    min-height: 100vh;
    position: relative;
    overflow: hidden;
    padding-bottom: ${HANDLE_HEIGHT}px;
`;

const BeverageWrapper = styled.div`
    max-width: 1024px;
    margin: 0 auto;
`;

const BeverageGrid = styled.div`
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(250px, 1fr));
    grid-gap: ${GAP};
    margin: ${GAP};
`;

const OverlayElement = styled.div`
    background: rgba(255, 255, 255, 0.6);
    position: fixed;
    width: 100%;
    height: 100%;
    display: flex;
    justify-content: center;
    align-items: center;
`;

class App extends Component {
    render() {
        return (
            <AppWrapper>
                {this.props.isBrewing && (
                    <OverlayElement>
                        <Loader />
                    </OverlayElement>
                )}
                <BeverageWrapper>
                    <BeverageGrid>
                        <Beverage id="1" title="white russian" imageUrl={WhiteRussian} />
                        <Beverage id="2" title="black russian"/>
                        <Beverage id="3" title="houba"/>
                        <Beverage id="4" title="kubicko"/>
                        <Beverage id="5" title="sydney"/>
                        <Beverage id="6" title="rum + rum"/>
                    </BeverageGrid>
                </BeverageWrapper>
                <Controls />
            </AppWrapper>
        );
    }
}

export default connect(
    state => ({
        isBrewing: isBrewing(state),
    })
)(App);
